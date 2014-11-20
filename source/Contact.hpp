#pragma once

#include <string>

//represents a contact which its information
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

