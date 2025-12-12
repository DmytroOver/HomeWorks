#pragma once
#include <string>

class Document
{
	std::string m_content;
public:
	Document(std::string text);
	void insert(size_t pos, const std::string& str);
	void erase(size_t pos, size_t count);
	void replace(size_t pos, size_t count, const std::string& str);
	const std::string& text() const;
};