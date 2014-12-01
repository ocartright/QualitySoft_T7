/*
 *Created By: Justus Flerlage
 *Edited By: Justus Flerlage
 */

#include "Application.hpp"

int main (int size, char** arguments)
{
	//calls the main() method in class Application, which then calls the run() method to run the program (either from the Console class or GraphicalUserInterface class)
	return Application().main(size, arguments);
}
