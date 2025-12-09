#include "ReplaceTextCommand.h"
#include <iostream>

ReplaceTextCommand::ReplaceTextCommand(std::shared_ptr<Document> doc,
										size_t pos,
										size_t count,
										std::string str) :
	m_doc(doc), m_pos(pos), m_count(count), m_str(std::move(str))
{
}

void ReplaceTextCommand::execute()
{
	std::shared_ptr<Document> doc = m_doc.lock();
	if (!doc)
	{
		std::cerr << "Replace failed. Invalid document.\n";
		return;
	}
	doc->replace(m_pos, m_count, m_str);
}