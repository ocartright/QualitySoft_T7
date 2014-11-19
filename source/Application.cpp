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
	//while loop manages the program
	bool programRunning;
	while(programRunning) {
		programRunning = console.run();  //console returns a false if user wants to exit the program
	}

	return 0;
}
