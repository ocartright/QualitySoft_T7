#pragma once

//forward delcaration
class Application;

//gui
class GraphicalUserInterface {
private:
	Application& application;

public:
	//constructor
	GraphicalUserInterface(Application& application);

	// main method
	void run();
};
