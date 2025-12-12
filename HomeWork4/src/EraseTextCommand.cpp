#include "EraseTextCommand.h"
#include <iostream>

EraseTextCommand::EraseTextCommand(std::shared_ptr<Document> doc, size_t pos, size_t count) :
	m_doc(doc), m_pos(pos), m_count(count)
{
}

void EraseTextCommand::execute()
{
	std::shared_ptr<Document> doc = m_doc.lock();
	if (!doc)
	{
		std::cerr << "Erase failed. Invalid document.\n";
		return;
	}
	doc->erase(m_pos, m_count);
}