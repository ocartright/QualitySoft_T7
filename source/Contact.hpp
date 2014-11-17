#pragma once

#include <string>

//represents a contact which its information
class Contact {
private:
   string firstName, lastName, streetAddress, email, phone, notes;
   
public:
	//constructors
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
