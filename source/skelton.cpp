//Andy
#include <iostream>
#include <vector>
using namespace std;

//represents a contact which its information
class Contact {
private:
   //contact information
   string firstName, lastName, streetAddress, email, phone, notes;
public:
    Contact();
    Contact(const string& fullName, const string& streetAddress, const string& email, 
    		const string& phone, const string& notes);
    Contact(const string& firstName, const string& lastName, const string& streetAddress, const string& email, 
    		const string& phone, const string& notes);

    //functions
    string getFullName() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getStreetAddress() const;
    const string& getEmail() const;
    const string& getPhone() const;
    const string& getNotes() const;

	void setFullName(const string& fullName);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setStreetAddress(const string& streetAddress);
    void setEmail(const string& email);
    void setPhone(const string& phone);
    void setNotes(const string& notes);
}

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
	void remove(const string & fullName);
	
	//get a contact by given element ( e.g. id )
	Contact& getContact(std::size_t element);
	const Contact& getContact(std::size_t element) const;
	
	//get a contact by given fullname
	Contact& getContact(const string & fullName);
	const Contact& getContact(const string & fullName) const;
};

//console interface
class Console {
private:

public:
	void main();
};

//gui
class GraphicalUserInterface {
private:

public:
	void main();
};

//represents the program as an object
class Application {
private:

public:
	int main(int size, char** arguments);
};

int main() {


    return 0;
}
