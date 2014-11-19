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
	if(userInput == "1") {  //shows all saved contacts
		contactManager.showContacts();
	} else if(userInput == "2") {  //enter a new contact
		Contact& newContact;
		contactManager.addContact(newContact);
		contactManager.save(newContact);
	} else if(userInput == "3") {  //search contact(s) by full name
		searchQuery = console.getQuery();
		contactManager.getContact(searchQuery);
	} else if(userInput == "4") {  //remove a contact
		searchQuery = console.getQuery;
		contactManager.remove(searchQuery);
	} else if(userInput == "5") {  //exit the program
		return false;  //this will be used in Application to stop te program
	}
}
