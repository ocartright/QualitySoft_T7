#include "ContactManager.hpp"

//returns amount of contacts
size_t ContactManager::getSize() const
{
   return this->contacts.size();
}

//creates new contact and returns a reference
void ContactManager::add(const Contact& contact)
{
   this->contacts.push_back(contact);
}

//get a contact by given element ( e.g. id )
Contact* ContactManager::getContact(std::size_t element)
{
   if (element < this->contacts.size())
      return &this->contacts[element];

   return nullptr;
}

const Contact* ContactManager::getContact(std::size_t element) const
{
   return this->getContact(element);
}

//get a contact by given fullname
Contact* ContactManager::getContact(const std::string& fullName)
{
   for (Contact &i : this->contacts)
   {
      if (i.getFullName() == fullName)
         return &i;
   }

   return nullptr;
}

const Contact* ContactManager::getContact(const std::string& fullName) const
{
   return this->getContact(fullName);
}

//methods for saving and writing all contacts
void ContactManager::save(const std::string& fileName) const
{

}
void ContactManager::load(const std::string& fileName)
{

}
