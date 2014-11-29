#pragma once

#include "ContactManager.hpp"

/* Represents the ContactList application as an object that uses either the Console interface or GUI. */
class Application {
private:
	//the ContactManager object that will manage the contact list throughout the program
	ContactManager contactManager;

public:
	/* Returns a reference to the application's contactManager object. */
	ContactManager& getContactManager();
	const ContactManager& getContactManager() const;

	/* Used to run the ContactList application itself. Calls the run() method from either Console class or GraphicalUserInterface class */
	int main(int size, char** arguments);
};
