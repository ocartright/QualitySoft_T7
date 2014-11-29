#include "ContactManager.hpp"
#include <fstream>

/* Returns the size of the 'contacts' vector, which represents the number of stored contacts. */
size_t ContactManager::getSize() const
{
   return this->contacts.size();
}

/* Adds a new Contact object that was created either in the Console class or GUI class to the 'contacts' vector. */
void ContactManager::add(const Contact& contact)
{
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

/*
	fileformat
	
	[limiter] is a specified limiter, used for limiting all fields and all contacts
	Indentation and break lines are only used for documentation and therefore not used in the fileformat itself
	[limiter] is a nullbyte (ascii value is zero)
	
	[limiter]
		[limiter][FullName][limiter]
		[limiter][LastName][limiter]
		[limiter][Address][limiter]
		[limiter][Email][limiter]
		[limiter][Phone][limiter]
		[limiter][Notes][limiter]
	[limiter]
*/

/* Writes all Contact objects in the 'contacts' vector into a specified file. */
void ContactManager::save(const std::string& fileName) const
{
	/*const char limiter=0;

    std::ofstream file(fileName, std::ios::binary);
    
    for(auto contact:this->contacts)
    {
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getFirstName().c_str(), contact.getFirstName().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getLastName().c_str(), contact.getLastName().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getAddress().c_str(), contact.getAddress().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getEmail().c_str(), contact.getEmail().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getPhone().c_str(), contact.getPhone().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    	file.write(contact.getNotes().c_str(), contact.getNotes().size());
    	file.put(limiter);
    	
    	file.put(limiter);
    }*/
}
namespace
{
	std::string readField(std::ifstream& stream)
	{
		std::string field("");
		char sign=0;
	
		while(!stream.eof()&&(sign=stream.get()))
		{
			field+=sign;
		}
		
		return field;
	}
}

/* Retrieves all Contact objects in the 'contacts' vector from a specified file. */
void ContactManager::load(const std::string& fileName)
{
	/*std::cout << "ContactManager::load\n" ;

    std::ifstream file(fileName, std::ios::binary);
    
    if(!file.is_open())
    	return;
    
    while(!file.eof())
    {
    	//if(sign)
    	//	continue;
    	char sign=0;
    	while(!file.eof()&&(sign=file.get()))
		{
			std::cout << sign;
		}
    		
    	//Contact contact(readField(file), readField(file), readField(file), readField(file), readField(file), readField(file));
    	
    	//this->contacts.push_back(contact);
    }
    
    std::cout.flush();*/
}
