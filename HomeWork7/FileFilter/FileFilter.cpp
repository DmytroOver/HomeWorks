#include "FileFilter.h"

#include <iostream>
#include <unordered_set>

FileFilter::FileFilter()
{
    using namespace std::literals::string_view_literals;
    m_predicateNames.reserve(3);
    m_predicates.reserve(3);
    m_predicateNames.emplace_back("Text"sv);
    m_predicates.emplace_back([](const FileInfo& fileInfo) { return fileInfo.extension == ".txt"; });

    m_predicateNames.emplace_back("Image"sv);
    const std::unordered_set imageExtensions = {".jpg"sv, ".jpeg"sv, ".png"sv, ".bmp"sv};
    m_predicates.emplace_back([imageExtensions](const FileInfo& fileInfo) -> bool
    {
        return imageExtensions.contains(fileInfo.extension);
    });

    m_predicateNames.emplace_back("Large"sv);
    constexpr size_t largeSizeThreshold = 1024 * 1024;
    m_predicates.emplace_back([](const FileInfo& fileInfo) -> bool
    {
        return fileInfo.size > largeSizeThreshold;
    });
}

void FileFilter::processDir(const fs::path& path)
{
    m_files.clear();
    for (const auto& entry : fs::recursive_directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            FileInfo info{entry.path(), entry.file_size(), entry.path().extension().string()};
            std::ranges::transform(info.extension, info.extension.begin(),
                                   [](const char c) { return std::tolower(c); });
            m_files.push_back(std::move(info));
        }
    }
}

void FileFilter::addPredicate(const std::string_view name, std::function<bool(const FileInfo&)> predicate)
{
    m_predicateNames.push_back(name);
    m_predicates.push_back(std::move(predicate));
}

void FileFilter::changePredicate(const size_t index, std::function<bool(const FileInfo&)> predicate)
{
    m_predicates[index] = std::move(predicate);
}

const std::vector<std::string_view>& FileFilter::getPredicateNames() const
{
    return m_predicateNames;
}

const std::function<bool(const FileInfo&)>& FileFilter::getPredicate(const int index) const
{
    return m_predicates[index];
}

FilterView FileFilter::getFiltered(
    const std::function<bool(const FileInfo&)>& predicate) const
{
    return m_files | std::views::filter(predicate);
}

FilterView FileFilter::getFiltered(const int index) const
{
    return getFiltered(getPredicate(index));
}
