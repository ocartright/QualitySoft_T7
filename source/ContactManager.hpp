#pragma once

#include <vector>
#include "Contact.hpp"

// manages all contacts by creating, modifying, deleting and granting access to them
class ContactManager {
private:
	std::vector<Contact> contacts;
	
public:
	// returns amount of contacts
	size_t getSize() const;

	//creates new contact and returns a reference
	Contact& add(const Contact& contact=Contact());
	
	//removes a contact by given element ( e.g. id ) or fullname
	void remove(std::size_t element);
	void remove(const std::string& fullName);
	
	//get a contact by given element ( e.g. id )
	Contact& getContact(std::size_t element);
	const Contact& getContact(std::size_t element) const;
	
	//get a contact by given fullname
	Contact& getContact(const std::string& fullName);
	const Contact& getContact(const std::string& fullName) const;
	
	//methods for saving and writing all contacts
	void save(const std::string& fileName) const;
	void write(const std::string& fileName);
};
