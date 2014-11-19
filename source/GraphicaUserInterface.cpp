#include "GraphicalUserInterface.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Pack.H>


GraphicalUserInterface::GraphicalUserInterface(Application& application):
	application(application)
{
}

void GraphicalUserInterface::main()
{
	Fl_Window* window=new Fl_Window(200,600);
	window->label("Contacts");

	Fl_Select_Browser* browser=new Fl_Select_Browser(10, 10, 180, 580);

    Fl_Pack* pack=new Fl_Pack( 200, 0, 580, 580, "Contact");
    pack->box(FL_BORDER_FRAME);

	browser->add("Orion");
	browser->add("Adam");
	browser->add("Justus");

	for (int i =0; i < 500; ++i)
        browser->add("Test");

	window->end();
	window->show();
	Fl::run();
}
