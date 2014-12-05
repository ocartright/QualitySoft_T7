/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage, Andy Alameddine
 */

#include "Contact.hpp"

/* Represents a single contact and hold all the information about that contact. */
//class constructors for the Contact class
Contact::Contact() :
	firstName(""),
	lastName(""),
	address(""),
	email(""),
	phone(""),
	notes("")
{
}
//the object can be instantiated and give one variable, the contact's full name
Contact::Contact(const std::string& fullName, const std::string& address, const std::string& email,
   const std::string& phone, const std::string& notes) :
   address(address),
   email(email),
   phone(phone),
   notes(notes)
{
   this->setFullName(fullName);
}
//the object can be instantiated and give two variables, the contact's first name and the contact's last name
Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& email,
   const std::string& phone, const std::string& notes) :
   firstName(firstName),
   lastName(lastName),
   address(address),
   email(email),
   phone(phone),
   notes(notes)
{
}

//all the getters that return the contact's credentials
/* Returns the full name of the contact as one string variable. */
std::string Contact::getFullName() const
{
   return this->firstName +" "+this->lastName;
}
/* Returns the first name of the contact as a string. */
const std::string& Contact::getFirstName() const
{
   return this->firstName;
}
/* Returns the last name of the contact as a string. */
const std::string& Contact::getLastName() const
{
   return this->lastName;
}
/* Returns the contact's address as a string. */
const std::string& Contact::getAddress() const
{
   return this->address;
}
/* Returns the contact's email address as a string. */
const std::string& Contact::getEmail() const
{
   return this->email;
}
/* Returns the contact's phone number as a string. */
const std::string& Contact::getPhone() const
{
   return this->phone;
}
/* Returns a special notes about the contact as a string. */
const std::string& Contact::getNotes() const
{
   return this->notes;
}

//all the setters that store the contact's credentials
/* Sets the full name of the contact as one string variable. */
void Contact::setFullName(const std::string& fullName)
{
   std::size_t i = fullName.find(' ');

   if (i != std::string::npos)
   {
      this->firstName = fullName.substr(0, i);
      this->lastName = fullName.substr(i, fullName.size() - i);
   }
   else
   {
      this->firstName = fullName;
   }
}
/* Sets the first name of the contact as a string. */
void Contact::setFirstName(const std::string& firstName)
{
   this->firstName = firstName;
}
/* Sets the last name of the contact as a string. */
void Contact::setLastName(const std::string& lastName)
{
   this->lastName = lastName;
}
/* Sets the contact's address as a string. */
void Contact::setAddress(const std::string& address)
{
   this->address = address;
}
/* Sets the contact's email address as a string. */
void Contact::setEmail(const std::string& email)
{
   this->email = email;
}
/* Sets the contact's phone number as a string. */
void Contact::setPhone(const std::string& phone)
{
   this->phone = phone;
}
/* Sets a special note about the contact as a string. */
void Contact::setNotes(const std::string& notes)
{
   this->notes = notes;
}
