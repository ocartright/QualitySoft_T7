/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage, Orion Vuong
 */

#pragma once

#include <vector>
#include <FL/Fl_Widget.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>

//forward delcaration
class Application;
class Contact;

/* User Interface (Graphical) that manages input from a windowed canvas and displays output on the canvas. */
class GraphicalUserInterface {
private:
	//used when instantiating a GraphicalUserInterface object. Specifies that an Application class will be using a GUI instead of a console interface.
	Application& application;

	//pointer to the user's currently selected contact
	Contact* selectedContact;

	//browser updater
	void updateBrowser();

	/* Callback methods required by Widgets below */
	static void onSelect(Fl_Widget* widget, void* p);
	static void onAdd(Fl_Widget* widget, void* p);
	static void onSave(Fl_Widget* widget, void* p);
	static void onRemove(Fl_Widget* widget, void* p);
	static void onSearch(Fl_Widget* widget, void* p);

	//widgets used for input
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
	Fl_Input search;

	//vector for mapping element of our browser to element of our contactManager
	std::vector <std::size_t> contactMap;

public:
	//the object can be instantiated and give one variable, the reference to the application that runs the program
	GraphicalUserInterface(Application& application);

	/* Used by the 'application' object to run the program if a GUI is being used in the program. */
	void run();
};
