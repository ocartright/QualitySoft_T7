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
Contact* const ContactManager::get(std::size_t element)
{
   if (element < this->contacts.size())
      return &this->contacts[element];

   return nullptr;
}

const Contact* const ContactManager::get(std::size_t element) const
{
   return this->get(element);
}

//get a contact by given fullname
Contact* const ContactManager::get(const std::string& fullName)
{
   for (Contact &i : this->contacts)
   {
      if (i.getFullName() == fullName)
         return &i;
   }

   return nullptr;
}

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

//methods for saving and writing all contacts
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
