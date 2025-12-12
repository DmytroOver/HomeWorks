#pragma once
#include "Command.h"
#include "Document.h"
#include <memory>

class EraseTextCommand : public Command
{
	std::weak_ptr<Document> m_doc;
	size_t m_pos = 0;
	size_t m_count = 0;
public:
	EraseTextCommand(std::shared_ptr<Document> doc, size_t pos, size_t count);
	void execute() override;
};