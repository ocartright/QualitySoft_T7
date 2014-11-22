#include "Application.hpp"
#include "ContactManager.hpp"
#include "GraphicalUserInterface.hpp"
//#include "Console.hpp"

//getter for contactManager
ContactManager& Application::getContactManager()
{
	return this->contactManager;
}
const ContactManager& Application::getContactManager() const
{
	return this->contactManager;
}

//main method
int Application::main(int size, char** arguments)
{
	GraphicalUserInterface(*this).run();
	//Console().run();
	
	return 0;
}
