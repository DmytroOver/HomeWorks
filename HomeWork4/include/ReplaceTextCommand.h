#pragma once
#include "Command.h"
#include "Document.h"
#include <memory>
#include <string>

class ReplaceTextCommand : public Command
{
	std::weak_ptr<Document> m_doc;
	size_t m_pos = 0;
	size_t m_count = 0;
	std::string m_str;
public:
	ReplaceTextCommand(std::shared_ptr<Document> doc, 
						size_t pos, 
						size_t count, 
						std::string str);
	void execute() override;
};