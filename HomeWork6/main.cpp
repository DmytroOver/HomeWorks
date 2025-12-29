// main.cpp : Defines the entry point for the application.
//

#include "main.h"

namespace fs = std::filesystem;

int main()
{
	fs::path path;
	std::cout << "Enter path to analyze: ";
	std::cin >> path;
	if (!fs::exists(path))
	{
		std::cout << "Path " << path << " does not exist." << std::endl;
		return 1;
	}
	FileCounter counter({".txt", ".jpg", ".png", ".bmp", ".exe"});
	for (const auto& entry : fs::recursive_directory_iterator(path))
	{
		if (entry.is_regular_file())
		{
			counter.add(entry.path().extension().string(), entry.file_size());
		}
	}
	std::cout << "Text files count (.txt): " << counter.getCountSize(".txt") << std::endl;
	std::cout << "Images count (.jpg, .png, .bmp): " << counter.getCountSize({ ".jpg", ".png", ".bmp" }) << std::endl;
	std::cout << "Executables count (.exe): " << counter.getCountSize(".exe") << std::endl;
	std::cout << "Other files count: " << counter.getCountSize() << std::endl;
	return 0;
}
