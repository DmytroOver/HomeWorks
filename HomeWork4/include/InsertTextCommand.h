#pragma once
#include "Command.h"
#include "Document.h"
#include <memory>
#include <string>

class InsertTextCommand : public Command
{
	std::weak_ptr<Document> m_doc;
	size_t m_pos = 0;
	std::string m_str;
public:
	InsertTextCommand(std::shared_ptr<Document> doc, size_t pos, std::string str);
	void execute() override;
};