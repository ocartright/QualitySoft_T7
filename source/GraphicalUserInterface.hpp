#pragma once

#include <FL/Fl_Widget.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Input.H>

//forward delcaration
class Application;
class Contact;

//gui
class GraphicalUserInterface {
private:
	Application& application;

	//callbacks
	static void onSelect(Fl_Widget* widget, void* p);
	static void onAdd(Fl_Widget* widget, void* p);
	static void onSave(Fl_Widget* widget, void* p);
	static void onRemove(Fl_Widget* widget, void* p);

	//current selected contact
	Contact* selectedContact;

	//browser
	void updateBrowser();

	//widgets
    Fl_Window window;
	Fl_Select_Browser browser;
	Fl_Button add;
	Fl_Button remove;
	Fl_Button save;
	Fl_Input firstName;
	Fl_Input lastName;
	Fl_Input address;
	Fl_Input email;
	Fl_Input phone;
	Fl_Input notes;

public:
	//constructor
	GraphicalUserInterface(Application& application);

	// main method
	void run();
};
