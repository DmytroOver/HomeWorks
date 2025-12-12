#include "InsertTextCommand.h"
#include <iostream>

InsertTextCommand::InsertTextCommand(std::shared_ptr<Document> doc, size_t pos, std::string str) :
	m_doc(doc), m_pos(pos), m_str(std::move(str))
{}

void InsertTextCommand::execute()
{
	std::shared_ptr<Document> doc = m_doc.lock();
	if (!doc)
	{
		std::cerr << "Insert failed. Invalid document.\n";
		return;
	}
	doc->insert(m_pos, m_str);
}