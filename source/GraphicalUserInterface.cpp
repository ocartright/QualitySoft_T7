/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage, Orion Vuong
 */

#include "GraphicalUserInterface.hpp"
#include "Application.hpp"
#include "Contact.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>

/* Callback methods required by Widgets below */
void GraphicalUserInterface::onSelect(Fl_Widget* widget, void* p)
{
    GraphicalUserInterface* gui=static_cast<GraphicalUserInterface*>(p);

	Contact* contact=gui->application.getContactManager().get(gui->contactMap[gui->browser.value()-1]);

	if(!contact)
		return;

	gui->selectedContact=contact;

    gui->firstName.value(contact->getFirstName().c_str());
    gui->lastName.value(contact->getLastName().c_str());
    gui->address.value(contact->getAddress().c_str());
    gui->email.value(contact->getEmail().c_str());
    gui->phone.value(contact->getPhone().c_str());
    gui->notes.value(contact->getNotes().c_str());
}
void GraphicalUserInterface::onAdd(Fl_Widget* widget, void* p)
{
    GraphicalUserInterface* gui=static_cast<GraphicalUserInterface*>(p);

    if(!strlen(gui->lastName.value()))
    {
        fl_alert("The Last Name is a required field!");
        return;
    }

    Contact contact;

    contact.setFirstName(gui->firstName.value());
    contact.setLastName(gui->lastName.value());
    contact.setAddress(gui->address.value());
    contact.setEmail(gui->email.value());
    contact.setPhone(gui->phone.value());
    contact.setNotes(gui->notes.value());

    gui->application.getContactManager().add(contact);

    gui->updateBrowser();
}
void GraphicalUserInterface::onSave(Fl_Widget* widget, void* p)
{
    GraphicalUserInterface* gui=static_cast<GraphicalUserInterface*>(p);

    if(!gui->selectedContact)
        return;

    gui->selectedContact->setFirstName(gui->firstName.value());
    gui->selectedContact->setLastName(gui->lastName.value());
    gui->selectedContact->setAddress(gui->address.value());
    gui->selectedContact->setEmail(gui->email.value());
    gui->selectedContact->setPhone(gui->phone.value());
    gui->selectedContact->setNotes(gui->notes.value());

    gui->updateBrowser();
}
void GraphicalUserInterface::onRemove(Fl_Widget* widget, void* p)
{
    GraphicalUserInterface* gui=static_cast<GraphicalUserInterface*>(p);

    if(!gui->selectedContact)
        return;

    gui->application.getContactManager().remove(gui->contactMap[gui->browser.value()-1]);

    gui->updateBrowser();

    gui->firstName.value("");
    gui->lastName.value("");
    gui->address.value("");
    gui->email.value("");
    gui->phone.value("");
    gui->notes.value("");
}
void GraphicalUserInterface::onSearch(Fl_Widget* widget, void* p)
{
    GraphicalUserInterface* gui=static_cast<GraphicalUserInterface*>(p);

    //update mapping
    gui->updateBrowser();
}

//browser updater
void GraphicalUserInterface::updateBrowser()
{
    this->browser.clear();
    this->contactMap.clear();

    //update map
    for(std::size_t i=0; i<this->application.getContactManager().getSize(); ++i)
    {
        if(!this->search.value())
            this->contactMap.push_back(i);
        else
        {
            const Contact* const contact=this->application.getContactManager().get(i);

            if(!contact)
                continue;

            if(contact->getFirstName().find(this->search.value())!=std::string::npos ||
               contact->getLastName().find(this->search.value())!=std::string::npos ||
               contact->getAddress().find(this->search.value())!=std::string::npos ||
               contact->getEmail().find(this->search.value())!=std::string::npos ||
               contact->getPhone().find(this->search.value())!=std::string::npos ||
               contact->getNotes().find(this->search.value())!=std::string::npos)
                this->contactMap.push_back(i);
        }
    }

	//insert map
    for(auto i:this->contactMap)
    {
        this->browser.add(this->application.getContactManager().get(i)->getFullName().c_str());
    }

    this->selectedContact=nullptr;
}

//the object can be instantiated and give one variable, the reference to the application that runs the program
GraphicalUserInterface::GraphicalUserInterface(Application& application):
	application(application),
	selectedContact(nullptr),
    window(600, 600, "Contacts"),
	browser(10, 10, 280, 540),
	add(300, 480, 290, 30, "Add"),
	remove(300, 520, 290, 30, "Remove"),
	save(300, 560, 290, 30, "Save"),
	firstName(380, 10, 210, 30, "First Name"),
	lastName(380, 50, 210, 30, "Last Name"),
	address(380, 130, 210, 30, "Address"),
	email(380, 170, 210, 30, "Email"),
	phone(380, 210, 210, 30, "Phone"),
	notes(380, 250, 210, 30, "Notes"),
	search(60, 560, 230, 30, "Search")
{
    this->browser.callback(GraphicalUserInterface::onSelect, this);
    this->remove.callback(GraphicalUserInterface::onRemove, this);
    this->add.callback(GraphicalUserInterface::onAdd, this);
    this->save.callback(GraphicalUserInterface::onSave, this);

    this->search.callback(GraphicalUserInterface::onSearch, this);
    this->search.when(FL_WHEN_CHANGED);

    this->updateBrowser();
}

/* Used by the 'application' object to run the program if a GUI is being used in the program. */
void GraphicalUserInterface::run()
{
	window.show();
	Fl::run();
}
