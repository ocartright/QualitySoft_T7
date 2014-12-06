/* 
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage, Orion Vuong
 */

#include "Application.hpp"
#include "ContactManager.hpp"
#include "GraphicalUserInterface.hpp"
#include "Console.hpp"

/* Returns a reference to the application's contactManager object. */
ContactManager& Application::getContactManager()
{
	return this->contactManager;
}
/* Returns a reference to the application's contactManager object. */
const ContactManager& Application::getContactManager() const
{
	return this->contactManager;
}

/* Used to run the ContactList application itself. Calls the run() method from either Console class or GraphicalUserInterface class */
int Application::main(int size, char** arguments)
{
    this->contactManager.load("contacts.xml");

    if(size>1 && std::string(arguments[1])=="--nogui")
        Console(*this).run();
    else
        GraphicalUserInterface(*this).run();
        
    this->contactManager.save("contacts.xml");
    
	return 0;
}
