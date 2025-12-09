// main.cpp : Defines the entry point for the application.
//

#include "main.h"

int main()
{
	std::shared_ptr<Document> doc1 = std::make_shared<Document>("Hello");
	std::shared_ptr<Document> doc2 = std::make_shared<Document>("World");

	CommandScheduler scheduler;

	std::cout << "doc1 initial: " << doc1->text() << std::endl;
	std::cout << "doc2 initial: " << doc2->text() << std::endl;

	scheduler.schedule(std::make_unique<InsertTextCommand>(doc1, 6, " World!"));
	scheduler.schedule(std::make_unique<InsertTextCommand>(doc2, 0, "Hello, "));

	{
		std::shared_ptr<Document> doc3 = std::make_shared<Document>("Temp");
		scheduler.schedule(std::make_unique<EraseTextCommand>(doc3, 0, 2));
	}

	scheduler.schedule(std::make_unique<ReplaceTextCommand>(doc1, 5, 5, " Everybody!"));
	scheduler.schedule(std::make_unique<ReplaceTextCommand>(doc2, 50, 50, "undefined"));

	scheduler.runAll();
	
	std::cout << "doc1 result: " << doc1->text() << std::endl;
	std::cout << "doc2 result: " << doc2->text() << std::endl;
	return 0;
}
