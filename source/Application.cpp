#include "Application.hpp"
#include "ContactManager.hpp"

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
	return 0;
}
