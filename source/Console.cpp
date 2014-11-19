#include "Console.hpp"
#include "Application.hpp"
#include "ContactManager.hpp"
#include <iostream>

Console::Console(Application & application):
	application(application)
{
}

//if the console interface is used in the program, this method will be used to run the program
void Console::run()
{
	while(input!=5)//or input<5
	{
		std::cout<<"Options: (1) Show All Contacts | (2) Enter New Contact | (3) Search Contacts | (4) Remove Contact | (5) Exit\n--> ";
		
		unsigned char input=0;
		std::cin>>input;
		
		switch(input)
		{
			case 1:
				this->showContacts();
				break;
			case 2:
				this->addContact();
				break;
			case 3:
				break;
			case 4:
				this->removeContact();
				break;
		}
	}
}
	
//get a contact by asking the user
Contact* Console::getContact() 
{
	std::cout << "Contact Query: " ;
	
	std::string query;
	std::cin >> query ;
	
	Contact* contact=this->application.getContactManager().getContact(query);
	
	if(contact)
		return contact;
		
	std::cout<<"‘"<<query<<"’ was not found in your contacts.";
		
	return nullptr;
}
const Contact* Console::getContact() const
{
	return this->getContact();
}

//show a contact by getting the contact with console input, itself, element or fullName
void Console::showContact() const
{
	const Contact* contact=this->getContact();
	
	if(contact)
		this->showContact(*contact);
}
void Console::showContact(const Contact& contact) const
{
	std::cout<<contact.getFullName()<<"\n"
			 <<contact.getStreetAddress()<<"\n"//todo: town, zipcode, state
			 <<contact.getEmail()<<"\n"
			 <<contact.getPhone()<<"\n\n";
}

//show all contacts
void Console::showContacts() const
{
	for(std::size_t i=0; i<this->application.getContactManager().getSize(); ++i)
		this->showContact(this->application.getContactManager().getContact(i));
}

//contact by getting the contact with console input, itself, element or fullName
void Console::removeContact()
{
	Contact* contact=this->getContact();
	
	if(contact)
		this->removeContact(*contact);
}
void Console::removeContact(Contact & contact)
{
	Contact* contact=this->getContact();
	
	if(contact)
		this->application.getContactManager().remove(contact);
}

//modify a contact by getting the contact with console input, itself, element or fullName
void Console::modifyContact()
{
	Contact* contact=this->getContact();
	
	if(contact)
		this->modifyContact(*contact);
}
void Console::modifyContact(Contact & contact)
{
}
