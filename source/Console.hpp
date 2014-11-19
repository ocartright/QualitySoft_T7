#pragma once

#include <string>

//forward declaration
class Application;
class Contact;

//console interface
class Console {
private:
	Application & application;

public:
	//constructor
	Console(Application & application);

	//main method
	void main();
	
	//get a contact by asking the user
	Contact* getContact() ;
	const Contact* getContact() const;
	
	//show a contact by getting the contact with console input, itself, element or fullName
	void showContact() const;
	void showContact(const Contact& contact) const;
	
	//show all contacts
	void showContacts() const;
	
	//contact by getting the contact with console input, itself, element or fullName
	void removeContact();
	void removeContact(Contact & contact);
	
	//modify a contact by getting the contact with console input, itself, element or fullName
	void modifyContact();
	void modifyContact(Contact & contact);
	
	//add a contact
	void addContact();
};
