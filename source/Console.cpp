#include "Console.hpp"

/*
Console::Console(Application & application):
	application(application)
{
}

//main method
void Console::main()
{
}
	
//get a contact by asking the user
Contact & Console::getContact() 
{
}
const Contact & Console::getContact() const
{
}

//show a contact by getting the contact with console input, itself, element or fullName
void Console::showContact() const
{
}
void Console::showContact(const Contact& contact) const
{
}
void Console::showContact(std::size_t element) const
{
}
void Console::showContact(const string& fullName) const
{
}

//show all contacts
void Console::showContacts() const
{
}
void Console::showContactsByFirstName(const string& firstName) const
{
}
void Console::showContactsByLastName(const string& lastName) const
{
}

//contact by getting the contact with console input, itself, element or fullName
void Console::removeContact()
{
}
void removeContact(Contact & contact)
{
}
void removeContact(std::size_t element)
{
}
void removeContact(const string& fullName)
{
}

//modify a contact by getting the contact with console input, itself, element or fullName
void modifyContact()
{
}
void modifyContact(Contact & contact)
{
}
void modifyContact(std::size_t element)
{
}
void modifyContact(const string& fullName)
{
}*/

//if the console interface is used in the program, this method will be used to run the program
bool Console::run() {
	showOptions();
	userInput = getInput();
	
	switch(userInput) {
	case 1:
		contactManager.showContacts();
		return true;
	case 2:
		Contact& newContact;
		contactManager.addContact(newContact);
		contactManager.save(newContact);
		return true;
	case 3:
		searchQuery = console.getQuery();
		contactManager.getContact(searchQuery);
		return true;
	case 4:
		searchQuery = console.getQuery;
		contactManager.remove(searchQuery);
		return true;
	case 5:
		return false;
	}
}
