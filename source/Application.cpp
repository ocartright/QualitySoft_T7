#include "Application.hpp"
#include "ContactManager.hpp"
#include "GraphicalUserInterface.hpp"
#include "Console.hpp"

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
    this->contactManager.load("contacts.txt");

    if(size>1 && std::string(arguments[1])==std::string("--nogui"))
        Console(*this).run();
    else
        GraphicalUserInterface(*this).run();


    this->contactManager.save("contacts.txt");

	return 0;
}
