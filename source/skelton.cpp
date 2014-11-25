/*
 * This file was created and edited by Andy Alameddine, Justus Flerlage, and Orion Vuong.
 * There is not one author of any class or method in this file. We worked together in a couple of meetings to create the skeleton.
 * Program successfully compiled and run.
 * Final edits and clean-ups done by Justus Flerlage.
 */

#include <iostream>
#include <vector>
#include <string>

//gui library
#include <FL/Fl_Widget.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Input.H>

//represents a contact which stores its information
class Contact {
private:
   std::string firstName, lastName, address, email, phone, notes;

public:
	//constructors
	Contact();
	Contact(const std::string& fullName, const std::string& address, const std::string& email,
			const std::string& phone, const std::string& notes);
	Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& email,
			const std::string& phone, const std::string& notes);

	//getters for private members
	std::string getFullName() const;
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getAddress() const;
	const std::string& getEmail() const;
	const std::string& getPhone() const;
	const std::string& getNotes() const;

	//setters for private members
	void setFullName(const std::string& fullName);
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setAddress(const std::string& address);
	void setEmail(const std::string& email);
	void setPhone(const std::string& phone);
	void setNotes(const std::string& notes);
};

// manages all contacts by creating, modifying, deleting and granting access to them
class ContactManager {
private:
	std::vector<Contact> contacts;
	
public:
	// returns amount of contacts
	size_t getSize() const;

	//creates new contact and returns a reference
	void add(const Contact& contact);
	
	//removes a contact by given element ( e.g. id ), object or fullname
	void remove(std::size_t element);
	void remove(const Contact& contact);
	void remove(const std::string& fullName);
	
	//get a contact by given element ( e.g. id )
	Contact* get(std::size_t element);
	const Contact* get(std::size_t element) const;
	
	//get a contact by given fullname
	Contact* get(const std::string& fullName);
	const Contact* get(const std::string& fullName) const;
	
	//methods for saving and writing all contacts
	void save(const std::string& fileName) const;
	void load(const std::string& fileName);
};

//console interface
class Console {
private:
	Application & application;
public:
	//constructor
	Console(Application & application);

	//if the console interface is used in the program, this method will be used to run the program
	void run();
	
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

//gui
class GraphicalUserInterface {
private:
	Application& application;

	//callbacks
	static void onSelect(Fl_Widget* widget, void* p);
	static void onAdd(Fl_Widget* widget, void* p);
	static void onSave(Fl_Widget* widget, void* p);
	static void onRemove(Fl_Widget* widget, void* p);

	//current selected contact
	Contact* selectedContact;

	//browser
	void updateBrowser();

	//widgets
    Fl_Window window;
	Fl_Select_Browser browser;
	Fl_Button add;
	Fl_Button remove;
	Fl_Button save;
	Fl_Input firstName;
	Fl_Input lastName;
	Fl_Input address;
	Fl_Input email;
	Fl_Input phone;
	Fl_Input notes;

public:
	//constructor
	GraphicalUserInterface(Application& application);

	// main method
	void run();
};

//represents the program as an object
class Application {
private:
	ContactManager contactManager;

public:
	//getter for contactManager
	ContactManager& getContactManager();
	const ContactManager& getContactManager() const;

	//main method
	int main(int size, char** arguments);
};

int main (int size, char** arguments)
{
	return Application().main(size, arguments);
}
