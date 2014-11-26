#include "Contact.hpp"

//constructors
Contact::Contact() :
	firstName(""),
	lastName(""),
	address(""),
	email(""),
	phone(""),
	notes("")
{
}
Contact::Contact(const std::string& fullName, const std::string& address, const std::string& email,
   const std::string& phone, const std::string& notes) :
   address(address),
   email(email),
   phone(phone),
   notes(notes)
{
   this->setFullName(fullName);
}
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

//getters
std::string Contact::getFullName() const
{
   return this->firstName +" "+this->lastName;
}

const std::string& Contact::getFirstName() const
{
   return this->firstName;
}

const std::string& Contact::getLastName() const
{
   return this->lastName;
}
const std::string& Contact::getAddress() const
{
   return this->address;
}
const std::string& Contact::getEmail() const
{
   return this->email;
}
const std::string& Contact::getPhone() const
{
   return this->phone;
}
const std::string& Contact::getNotes() const
{
   return this->notes;
}

//setters
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

void Contact::setFirstName(const std::string& firstName)
{
   this->firstName = firstName;
}
void Contact::setLastName(const std::string& lastName)
{
   this->lastName = lastName;
}
void Contact::setAddress(const std::string& address)
{
   this->address = address;
}
void Contact::setEmail(const std::string& email)
{
   this->email = email;
}
void Contact::setPhone(const std::string& phone)
{
   this->phone = phone;
}
void Contact::setNotes(const std::string& notes)
{
   this->notes = notes;
}

/*dksajdkjasdkasdjaksd*/