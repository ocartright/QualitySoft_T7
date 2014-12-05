/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage
 */

#pragma once

#include <string>

//forward declaration
class Application;
class Contact;

/* User Interface that manages console input from the user and displays output in the console. */
class Console {
private:
	//used when instantiating a Console object. Specifies that an Application class will be using the console interface instead of a GUI.
	Application & application;
public:
	//the object can be instantiated and give one variable, the reference to the application that runs the program
	Console(Application & application);

	/* Used by the 'application' object to run the program if a console interface is being used in the program. */
	void run();
	
	/* Returns a pointer to a Contact object, which is found using the user's input in the console. */
	Contact* getContact() ;
	/* Returns a pointer to a Contact object, which is found using the user's input in the console. */
	const Contact* getContact() const;
	
	/* Shows a contact's credentials. */
	void showContact() const;
	/* Shows a specific contact's credentials that were retrieved by the getContact() method. */
	void showContact(const Contact& contact) const;
	
	/* Shows credentials of all contacts in the 'contacts' vector. */
	void showContacts() const;
	
	/* Modifies a Contact object. Used to enter information for a new Contact, which is retrieved with the getContact() method */
	void modifyContact();
	/* Modifies the Contact object sent in. */
	void modifyContact(Contact & contact);
	
	/* Removes a Contact object from the 'contacts' vector */
	void removeContact();
	/* Removes a specific Contact object, retrieved using the getContact() method, from the 'contacts' vector. */
	void removeContact(Contact & contact);
	
	/* Adds a new Contact object to the 'contacts' vector */
	void addContact();
};
