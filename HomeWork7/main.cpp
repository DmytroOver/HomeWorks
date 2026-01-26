// main.cpp : Defines the entry point for the application.
//

#include "main.h"

namespace fs = std::filesystem;

void addOtherFilesPredicate(FileFilter& filter)
{
	constexpr std::string_view name = "Other";
	size_t size = filter.getPredicateNames().size();
	filter.addPredicate(name, [&filter, size](const FileInfo& fileInfo) -> bool
	{
		for (int i = 0; i < size; ++i)
		{
			if (filter.getPredicate(i)(fileInfo))
			{
				return false;
			}
		}
		return true;
	});
}

void changeImagesPredicate(FileFilter& filter)
{
	using namespace std::literals::string_view_literals;
	const std::vector<std::string_view>& names = filter.getPredicateNames();
	auto it = std::ranges::find(names, "Image");
	if (it != names.end())
	{
		const size_t index = std::distance(names.begin(), it);
		// adding .heic extension to images
		const std::unordered_set imageExtensions = {".jpg"sv, ".jpeg"sv, ".png"sv, ".bmp"sv, ".heic"sv};
		filter.changePredicate(index, [imageExtensions](const FileInfo& fileInfo) -> bool
		{
			return imageExtensions.contains(fileInfo.extension);
		});
	}
}

void printMenu(const std::vector<std::string_view>& names)
{
	std::cout << "Choose the filter:\n";
	std::cout << "0. Exit.\n";
	for (int i = 0; i < names.size(); ++i)
	{
		std::cout << i + 1 << ". " << names[i] << " files.\n";
	}
}

int main()
{
	FileFilter filter;
	addOtherFilesPredicate(filter);
	changeImagesPredicate(filter);
	std::string input;
	for (;;)
	{
		std::cout << "Enter path to analyze or type 'exit' to exit: ";
		std::getline(std::cin, input);
		if (input == "exit")
		{
			return 0;
		}
		const fs::path path = input;
		if (!fs::exists(path))
		{
			std::cout << "Path " << path << " does not exist." << std::endl;
			continue;
		}
		if (!fs::is_directory(path))
		{
			std::cout << "Path " << path << " is not a directory." << std::endl;
			continue;
		}
		filter.processDir(path);

		for (;;)
		{
			int choice = 0;
			printMenu(filter.getPredicateNames());
			std::getline(std::cin, input);
			try
			{
				choice = std::stoi(input);
			}
			catch (const std::exception& e)
			{
				std::cout << "Please enter a valid choice.\n";
				continue;
			}
			if (choice == 0)
			{
				break;
			}
			int predicateIndex = choice - 1;
			if (predicateIndex < 0 || predicateIndex >= filter.getPredicateNames().size())
			{
				std::cout << "Please enter a valid choice.\n";
				continue;
			}
			auto filtered = filter.getFiltered(choice - 1);
			size_t count = 0;
			size_t size = 0;
			for (const auto& entry : filter.getFiltered(choice - 1))
			{
				++count;
				size += entry.size;
				std::cout << entry.path << std::endl;
			}
			std::cout << "Files count: " << count << " size: " << size << " bytes\n";
		}
	}
}
