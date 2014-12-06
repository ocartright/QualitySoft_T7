/*
 *Created By: Justus Flerlage
 *Edited By: Andy Alameddine
 */

#include "ContactManager.hpp"
#include <fstream>
#include "pugixml.hpp"

/* Returns the size of the 'contacts' vector, which represents the number of stored contacts. */
size_t ContactManager::getSize() const
{
   return this->contacts.size();
}

/* Adds a new Contact object that was created either in the Console class or GUI class to the 'contacts' vector. */
void ContactManager::add(const Contact& contact)
{
	if(!contact.getLastName().empty())
		this->contacts.push_back(contact);
}

//overloaded method: removes an existing contact using a given element
/* Removes an existing contact using the position of the Contact in the 'contacts' vector. */
void ContactManager::remove(std::size_t element)
{
	this->contacts.erase(this->contacts.begin()+element);
}
/* Removes an existing contact using a reference to a Contact object. */
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
/* Removes an existing contact using a reference to the contact's full name. */
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

//overloaded method: returns a pointer to a Contact object using a given element
/* Returns a reference to a Contact object using the position of the Contact in the 'contacts' vector. Contact object may be modified. */
Contact* const ContactManager::get(std::size_t element)
{
   if (element < this->contacts.size())
      return &this->contacts[element];

   return nullptr;
}
/* Returns a pointer to a Contact object using the position of the Contact in the 'contacts' vector.  */
const Contact* const ContactManager::get(std::size_t element) const
{
   return this->get(element);
}
/* Returns a pointer to a Contact object using a reference to the contact's full name. May modify the reference to the object or the object itself. */
Contact* const ContactManager::get(const std::string& fullName)
{
   for (Contact &i : this->contacts)
   {
      if (i.getFullName() == fullName)
         return &i;
   }

   return nullptr;
}
/* Returns a reference to a Contact object using a reference to the contact's full name. May not be modified at all. */
const Contact* const ContactManager::get(const std::string& fullName) const
{
   return this->get(fullName);
}

/* Writes all Contact objects in the 'contacts' vector into a specified file. */
void ContactManager::save(const std::string& fileName) const
{
    pugi::xml_document doc;

    for(auto i:this->contacts)
    {
        pugi::xml_node node=doc.append_child("contact");

        node.append_attribute("firstName")=i.getFirstName().c_str();
        node.append_attribute("lastName")=i.getFirstName().c_str();
        node.append_attribute("address")=i.getAddress().c_str();
        node.append_attribute("email")=i.getEmail().c_str();
        node.append_attribute("phone")=i.getPhone().c_str();
        node.append_attribute("notes")=i.getNotes().c_str();
    }

    doc.save_file(fileName.c_str());
}
/* Retrieves all Contact objects in the 'contacts' vector from a specified file. */
void ContactManager::load(const std::string& fileName)
{
    pugi::xml_document doc;

    if(!doc.load_file(fileName.c_str()))
        return;

    for(auto i:doc)
    {
        Contact contact(i.attribute("firstName").as_string(),
                        i.attribute("lastName").as_string(),
                        i.attribute("address").as_string(),
                        i.attribute("email").as_string(),
                        i.attribute("phone").as_string(),
                        i.attribute("notes").as_string());

        this->contacts.push_back(contact);
    }
}
