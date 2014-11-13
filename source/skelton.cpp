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

    //functions
    const string& getFirstName() const;
    const string& getLastName() const;
    const string& getStreetAddress() const;
    const string& getEmail() const;
    const string& getPhone() const;
    const string& getNotes() const;

    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setStreetAddress(const string &streetAddress);
    void setEmail(const string &email);
    void setPhone(const string &phone);
    void setNotes(const string &notes);
}

// manages all contacts by creating, modifying, deleting and granting access to them
class ContactManager {
private:
    vector<Contact> contacts;
public:
    //functions
    /* create a new Contact object */
    void makeNewContact();
    /* access and modify a Contact object */
    const Contact& getContact() const;
    /* access and modify a Contact object */
    Contact& getContact();
};

//console interface
class Console {
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
