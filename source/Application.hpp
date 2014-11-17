#pragma once

//forward declaration
class ContactManager;

//represents the program as an object
class Application {
private:
	ContactManager & contactManager;

public:
	//getter for contactManager
	ContactManager& getContactManager();
	const ContactManager& getContactManager() const;

	//main method
	int main(int size, char** arguments);
};
