//Andy
#include <iostream>
#include <vector>
using namespace std;

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

class Console {
private:

public:

};

int main() {


    return 0;
}
