#include "CommandScheduler.h"

void CommandScheduler::schedule(std::unique_ptr<Command> cmd)
{
	m_pending.push(std::move(cmd));
}

void CommandScheduler::runAll()
{
	while (!m_pending.empty())
	{
		std::unique_ptr<Command> cmd = std::move(m_pending.front());
		m_pending.pop();
		if (cmd)
		{
			cmd->execute();
		}
	}
}