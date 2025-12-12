#include "Document.h"
#include <iostream>

Document::Document(std::string text): m_content(std::move(text))
{}

void Document::insert(size_t pos, const std::string& str)
{
	if (pos > m_content.size())
	{
		std::cerr << "Insert failed. Out of range.\n";
		return;
	}
	m_content = m_content.insert(pos, str);
}

void Document::erase(size_t pos, size_t count)
{
	if (pos > m_content.size())
	{
		std::cerr << "Erase failed. Out of range.\n";
		return;
	}
	m_content.erase(pos, count);
}

void Document::replace(size_t pos, size_t count, const std::string& str)
{
	if (pos > m_content.size())
	{
		std::cerr << "Replace failed. Out of range.\n";
		return;
	}
	m_content = m_content.replace(pos, count, str);
}

const std::string& Document::text() const
{
	return m_content;
}