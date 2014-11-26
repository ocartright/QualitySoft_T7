/*
 * This file was created and edited by Andy Alameddine, Justus Flerlage, and Orion Vuong.
 * There is not one author of any class or method in this file. We worked together in a couple of meetings to create the skeleton.
 * Program successfully compiled and run.
 * Final edits and clean-ups done by Justus Flerlage and Orion Vuong.
 */

#include <iostream>
#include <vector>
#include <string>

//gui library (used in GUI version only and must be an included library to compile properly)
#include <FL/Fl_Widget.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Input.H>

//class pre-declarations so that compiler knows these types exist in the program
class Application;
class Contact;
class ContactManager;
class Console;

/* Represents a single contact and hold all the information about that contact. */
class Contact {
private:
   //general information about the contact that the user would be interested in
   std::string firstName, lastName, address, email, phone, notes;

public:
	//class constructors for the Contact class
	Contact();
	//the object can be instantiated and give one variable, the contact's full name
	Contact(const std::string& fullName, const std::string& address, const std::string& email,
			const std::string& phone, const std::string& notes);
	//the object can be instantiated and give two variables, the contact's first name and the contact's last name
	Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& email,
			const std::string& phone, const std::string& notes);
	
	//all the getters that return the contact's credentials
	/* Returns the full name of the contact as one string variable. */
	std::string getFullName() const;
	/* Returns the first name of the contact as a string. */
	const std::string& getFirstName() const;
	/* Returns the last name of the contact as a string. */
	const std::string& getLastName() const;
	/* Returns the contact's address as a string. */
	const std::string& getAddress() const;
	/* Returns the contact's email address as a string. */
	const std::string& getEmail() const;
	/* Returns the contact's phone number as a string. */
	const std::string& getPhone() const;
	/* Returns a special notes about the contact as a string. */
	const std::string& getNotes() const;

	//all the setters that store the contact's credentials
	/* Sets the full name of the contact as one string variable. */
	void setFullName(const std::string& fullName);
	/* Sets the first name of the contact as a string. */
	void setFirstName(const std::string& firstName);
	/* Sets the last name of the contact as a string. */
	void setLastName(const std::string& lastName);
	/* Sets the contact's address as a string. */
	void setAddress(const std::string& address);
	/* Sets the contact's email address as a string. */
	void setEmail(const std::string& email);
	/* Sets the contact's phone number as a string. */
	void setPhone(const std::string& phone);
	/* Sets a special notes about the contact as a string. */
	void setNotes(const std::string& notes);
};

/* Manages all Contact objects. Creates new Contact objects and deletes and/or grants access to existing Contact objects. */
class ContactManager {
private:
	//a vector that holds all Contact objects
	std::vector<Contact> contacts;
	
public:
	/* Returns the size of the 'contacts' vector, which represents the number of stored contacts. */
	size_t getSize() const;

	/* Adds a new Contact object that was created either in the Console class or GUI class to the 'contacts' vector. */
	void add(const Contact& contact);
	
	//overloaded method: removes an existing contact using a given element
	/* Removes an existing contact using the position of the Contact in the 'contacts' vector. */
	void remove(std::size_t element);
	/* Removes an existing contact using a reference to a Contact object. */
	void remove(const Contact& contact);
	/* Removes an existing contact using a reference to the contact's full name. */
	void remove(const std::string& fullName);
	
	//overloaded method: returns a pointer to a Contact object using a given element
	/* Returns a reference to a Contact object using the position of the Contact in the 'contacts' vector. Contact object may be modified. */
	Contact* get(std::size_t element);
	/* Returns a pointer to a Contact object using the position of the Contact in the 'contacts' vector.  */
	const Contact* get(std::size_t element) const;
	/* Returns a pointer to a Contact object using a reference to the contact's full name. May modify the reference to the object or the object itself. */
	Contact* get(const std::string& fullName);
	/* Returns a reference to a Contact object using a reference to the contact's full name. May not be modified at all. */
	const Contact* get(const std::string& fullName) const;
	
	/* Writes all Contact objects in the 'contacts' vector into a specified file. */
	void save(const std::string& fileName) const;
	/* Retrieves all Contact objects in the 'contacts' vector from a specified file. */
	void load(const std::string& fileName);
};

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
	
	/* Removes a Contact object from the 'contacts' vector */
	void removeContact();
	/* Removes a specific Contact object, retrieved using the getContact() method, from the 'contacts' vector. */
	void removeContact(Contact & contact);
	
	/* Adds a new Contact object to the 'contacts' vector */
	void addContact();
};

/* User Interface (Graphical) that manages input from a windowed canvas and displays output on the canvas. */
class GraphicalUserInterface {
private:
	//used when instantiating a GraphicalUserInterface object. Specifies that an Application class will be using a GUI instead of a console interface.
	Application& application;

	/* Callback methods required by Widgets below */
	static void onSelect(Fl_Widget* widget, void* p);
	static void onAdd(Fl_Widget* widget, void* p);
	static void onSave(Fl_Widget* widget, void* p);
	static void onRemove(Fl_Widget* widget, void* p);

	//reference to the user's currently selected contact
	Contact* selectedContact;

	//browser updater
	void updateBrowser();

	//widgets used for input
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
	//the object can be instantiated and give one variable, the reference to the application that runs the program
	GraphicalUserInterface(Application& application);

	/* Used by the 'application' object to run the program if a GUI is being used in the program. */
	void run();
};

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

int main (int size, char** arguments)
{
	//calls the main() method in class Application, which then calls the run() method to run the program (either from the Console class or GraphicalUserInterface class)
	return Application().main(size, arguments);
}
