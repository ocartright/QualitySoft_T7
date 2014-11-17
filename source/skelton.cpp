//Andy
#include <iostream>
#include <vector>
using namespace std;

//represents a contact which its information
class Contact {
private:
   string firstName, lastName, streetAddress, email, phone, notes;
   
public:
	//consutructors
    Contact();
    Contact(const string& fullName, const string& streetAddress, const string& email, 
    		const string& phone, const string& notes);
    Contact(const string& firstName, const string& lastName, const string& streetAddress, const string& email, 
    		const string& phone, const string& notes);

    //getters for private members
    string getFullName() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getStreetAddress() const;
    const string& getEmail() const;
    const string& getPhone() const;
    const string& getNotes() const;

	//setters for private members
	void setFullName(const string& fullName);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setStreetAddress(const string& streetAddress);
    void setEmail(const string& email);
    void setPhone(const string& phone);
    void setNotes(const string& notes);
};

// manages all contacts by creating, modifying, deleting and granting access to them
class ContactManager {
private:
    vector<Contact> contacts;
    
public:
	// returns amount of contacts
	size_t getSize() const;

	//creates new contact and returns a reference
	Contact& add(const Contact& contact=Contact());
	
	//removes a contact by given element ( e.g. id ) or fullname
	void remove(std::size_t element);
	void remove(const string& fullName);
	
	//get a contact by given element ( e.g. id )
	Contact& getContact(std::size_t element);
	const Contact& getContact(std::size_t element) const;
	
	//get a contact by given fullname
	Contact& getContact(const string& fullName);
	const Contact& getContact(const string& fullName) const;
	
	//methods for saving and writing all contacts
	void save(const string& fileName) const;
	void write(const string& fileName);
};

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

//gui
class GraphicalUserInterface {
private:

public:
	// main method
	void main();
};

//represents the program as an object
class Application {
private:
	ContactManager & contactManager;

public:
	//getter for contactManager
	ContactManager& getContactManager();
	const ContactManager& getContactManager() const;

	//method main
	int main(int size, char** arguments);
};

int main(int size, char** arguments) {
	return Application().main(size, arguments);
}
