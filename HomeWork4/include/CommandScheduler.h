#pragma once
#include "Command.h"
#include <memory>
#include <queue>

class CommandScheduler
{
	std::queue<std::unique_ptr<Command>> m_pending;
public:
	void schedule(std::unique_ptr<Command> cmd);
	void runAll();
};