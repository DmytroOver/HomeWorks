#pragma once

#include <vector>
#include <filesystem>
#include <string>
#include <functional>
#include <ranges>

namespace fs = std::filesystem;

struct FileInfo
{
    fs::path path;
    size_t size;
    std::string extension;
};

using FilterView = std::ranges::filter_view<std::ranges::ref_view<const std::vector<FileInfo>>, std::function<bool
                                                (const FileInfo&)>>;

class FileFilter
{
    std::vector<FileInfo> m_files;
    std::vector<std::string_view> m_predicateNames;
    std::vector<std::function<bool(const FileInfo&)>> m_predicates;

public:
    FileFilter();
    void processDir(const fs::path& path);
    void addPredicate(std::string_view name, std::function<bool(const FileInfo&)> predicate);
    void changePredicate(size_t index, std::function<bool(const FileInfo&)>);
    [[nodiscard]] const std::vector<std::string_view>& getPredicateNames() const;
    [[nodiscard]] const std::function<bool(const FileInfo&)>& getPredicate(int index) const;
    [[nodiscard]] FilterView getFiltered(const std::function<bool(const FileInfo&)>& predicate) const;
    [[nodiscard]] FilterView getFiltered(int index) const;
};
