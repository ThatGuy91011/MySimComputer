#include <iostream>
#include <string>
#include "CommandShell.h"
#include "Memory.h"


int main()
{
	// start up variables for the computer
	CommandShell cmdShell;
	Memory RAM;

	// user experience, make it fun
	std::cout << "***Starting SkyNet Command Console 2020***";
	std::cout << "\n*Welcome to the Future*\n";
	std::cout << "\n\nMemory loaded..";
	std::cout << "\nCommand Shell Interface operational...";
	// let the user know we are up and running
	std::cout << "\n\nSKYNET is now online\n\n";
	

	// computer run loop
	do
	{
		// gather command from user
		std::string userCmd;
		std::cout << "\n\nPlease enter your command\n";
		getline(std::cin, userCmd);
		// pass command to command shell function
		cmdShell.IntakeCommand(userCmd, RAM);

	} while (true); // the infinite loop should be OK since the Exit command will close the program
	return 0;
}