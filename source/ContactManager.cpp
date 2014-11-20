#include "ContactManager.hpp"
#include <fstream>

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

//removes a contact by given element ( e.g. id ), object or fullname
void ContactManager::remove(std::size_t element)
{
	this->contacts.erase(this->contacts.begin()+element);
}
void ContactManager::remove(const Contact& contact)
{
	for(std::vector<Contact>::iterator i=this->contacts.begin(); i!=this->contacts.end(); ++i)
	{
		if((&*i)==(&contact))
		{
			this->contacts.erase(i);
			break;
		}
	}
}
void ContactManager::remove(const std::string& fullName)
{
    for(std::vector<Contact>::iterator i=this->contacts.begin(); i!=this->contacts.end(); ++i)
	{
		if(i->getFullName()==fullName)
		{
			this->contacts.erase(i);
			break;
		}
	}
}

//get a contact by given element ( e.g. id )
Contact* ContactManager::get(std::size_t element)
{
   if (element < this->contacts.size())
      return &this->contacts[element];

   return nullptr;
}

const Contact* ContactManager::get(std::size_t element) const
{
   return this->get(element);
}

//get a contact by given fullname
Contact* ContactManager::get(const std::string& fullName)
{
   for (Contact &i : this->contacts)
   {
      if (i.getFullName() == fullName)
         return &i;
   }

   return nullptr;
}

const Contact* ContactManager::get(const std::string& fullName) const
{
   return this->get(fullName);
}

//methods for saving and writing all contacts
void ContactManager::save(const std::string& fileName) const
{

}
void ContactManager::load(const std::string& fileName)
{

}
