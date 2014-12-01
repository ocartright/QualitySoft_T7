/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage
 */

#pragma once

#include <string>

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
	/* Sets a special note about the contact as a string. */
	void setNotes(const std::string& notes);
};
