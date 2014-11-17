#pragma once

#include <string>

//forward declaration
class Application;

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
	Contact & getContact() ;
	const Contact & getContact() const;
	
	//show a contact by getting the contact with console input, itself, element or fullName
	void showContact() const;
	void showContact(const Contact& contact) const;
	void showContact(std::size_t element) const;
	void showContact(const string& fullName) const;
	
	//show all contacts
	void showContacts() const;
	void showContactsByFirstName(const string& firstName) const;
	void showContactsByLastName(const string& lastName) const;
	
	//contact by getting the contact with console input, itself, element or fullName
	void removeContact();
	void removeContact(Contact & contact);
	void removeContact(std::size_t element);
	void removeContact(const string& fullName);
	
	//modify a contact by getting the contact with console input, itself, element or fullName
	void modifyContact();
	void modifyContact(Contact & contact);
	void modifyContact(std::size_t element);
	void modifyContact(const string& fullName);
	
	//add a contact
	void addContact();
};
