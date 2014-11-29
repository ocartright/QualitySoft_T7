#include "Console.hpp"
#include "Application.hpp"
#include "ContactManager.hpp"
#include <iostream>

/* User Interface that manages console input from the user and displays output in the console. */
Console::Console(Application & application):
	//the object can be instantiated and give one variable, the reference to the application that runs the program
	application(application)
{
}

/* Used by the 'application' object to run the program if a console interface is being used in the program. */
void Console::run()
{
	unsigned int input=0;

	while(input!=5)//or input<5
	{
		std::cout<<"Options: (1) Show All Contacts | (2) Enter New Contact | (3) Search Contacts | (4) Remove Contact | (5) Exit\n--> ";

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
				this->getContact();
				break;
			case 4:
				this->removeContact();
				break;
		}
	}
	std::cout << "\n*Your contacts have been updated. Goodbye!*";
}

/* Returns a pointer to a Contact object, which is found using the user's input in the console. */
Contact* Console::getContact()
{
	bool userSearching;
	while(userSearching) {
		std::cout << "To search, enter a first name, last name, full name, zip code, email, or phone number. To go back, etner 'goback'\n";
		
		std::cout << "Contact Query\n--> ";
		
		std::string query;
		std::cin >> query ;
		
		if(query != "goback") {
			Contact* contact=this->application.getContactManager().get(query);
			if(contact)
				return contact;
			
			std::cout<<"\n‘"<<query<<"’ was not found in your contacts.\n";
		}
		userSearching = false;
	}
	return nullptr;
}
/* Returns a pointer to a Contact object, which is found using the user's input in the console. */
const Contact* Console::getContact() const
{
	return this->getContact();
}

/* Shows a contact's credentials. */
void Console::showContact() const
{
	const Contact* contact=this->getContact();

	if(contact)
		this->showContact(*contact);
}
/* Shows a specific contact's credentials that were retrieved by the getContact() method. */
void Console::showContact(const Contact& contact) const
{
	std::cout<<contact.getFullName()<<"\n"
	 	 <<contact.getAddress()<<"\n"//todo: town, zipcode, state
		 <<contact.getEmail()<<"\n"
		 <<contact.getPhone()<<"\n\n";
}

/* Shows credentials of all contacts in the 'contacts' vector. */
void Console::showContacts() const
{
	for(std::size_t i=0; i<this->application.getContactManager().getSize(); ++i)
		this->showContact(*this->application.getContactManager().get(i));
}

/* Removes a Contact object from the 'contacts' vector */
void Console::removeContact()
{
	Contact* contact=this->getContact();

	if(contact)
		this->removeContact(*contact);
}
/* Removes a specific Contact object, retrieved using the getContact() method, from the 'contacts' vector. */
void Console::removeContact(Contact & contact)
{
	this->application.getContactManager().remove(contact);
}

/* Modifies a Contact object. Used to enter information for a new Contact, which is retrieved with the getContact() method */
void Console::modifyContact()
{
	Contact* contact=this->getContact();

	if(contact)
		this->modifyContact(*contact);
}
/* Modifies the Contact object sent in. */
void Console::modifyContact(Contact & contact)
{
	std::string input;

	std::cout<<"First Name: ";
	std::cin>>input;
	contact.setFirstName(input);

	std::cout<<"Last Name: ";
	std::cin>>input;
	contact.setLastName(input);

	std::cout<<"Address: ";
	std::cin>>input;
	contact.setAddress(input);

	std::cout<<"Email: ";
	std::cin>>input;
	contact.setEmail(input);

	std::cout<<"Phone Number: ";
	std::cin>>input;
	contact.setPhone(input);

	std::cout<<"Notes: ";
	std::cin>>input;
	contact.setNotes(input);
}*/

/* Adds a new Contact object to the 'contacts' vector */
void Console::addContact()
{
	std::cout<<"New Contact Credentials:\n\n";

	Contact contact;

	this->modifyContact(contact);

	this->application.getContactManager().add(contact);

	std::cout<<"\n\n*New Contact has been entered*";

}
