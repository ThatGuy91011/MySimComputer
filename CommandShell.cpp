#include "CommandShell.h"
#include "Memory.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

void CommandShell::IntakeCommand(std::string input, Memory RAM)
{
	// call process
	ProcessCommand(input, RAM);
}

void CommandShell::ProcessCommand(std::string command, Memory RAM)
{
	// check the input and launch appropriate section
	if (command == "Help" || command == "help")
	{
		// launch display help function
		DisplayHelp();
	}
	else if (command == "DisplayMem" || command == "displaymem" || command == "dm")
	{
		// launch display memory function
		DisplayMem(RAM);
	}
	else if (command == "Load" || command == "load")
	{
		// launch memory loader function
		LoadIntoMem(RAM);
	}
	else if (command == "Run" || command == "run")
	{
		// start and run the code
		RunFromMem(RAM);
	}
	else if (command == "Exit" || command == "exit")
	{
		// exit the shell - shutdown the sim computer
		ConfirmClose();
	}
	else
	{
		// give an error to the user
		std::cout << "\n*Unknown Command*\n";
	}
}

void CommandShell::DisplayHelp()
{
	// list out the commands for the user
	std::cout << "\n\n\t ***Help Command List***\n";
	std::cout << "\nHelp - Displays this Help Menu";
	std::cout << "\nLoad - Loads a program into memory";
	std::cout << "\nRun - Runs the program in memory";
	std::cout << "\nDisplayMem - Displays all memory locations and values";
	std::cout << "\nExit - Exits this Shell";
}

void CommandShell::DisplayMem(Memory RAM)
{
	// show all values in all memory indecies
	for (int i = 0; i < 100; i++)
	{
		// show the user
		std::cout << RAM.GetAddress(i) << std::endl;
	}
}

void CommandShell::LoadIntoMem(Memory RAM)
{
	// file variable
	std::fstream file;
	// strings to hold ...
	std::string word, filename;
	int address, value, line;

	// ask user
	std::cout << "\nPlease enter filename:";
	// gather input
	std::cin >> filename;

	//opening file
	file.open(filename);

	// show the user it is a work in progress
	std::cout << "Parsing file data!" << std::endl;

	// read the lines of the file
	while (std::getline(file, word))
	{
		// try catch to convert string to int
		try
		{
			// String To Int
			line = std::stoi(word);
			// divide line by 100 to get first 2 digits
			address = line / 100;
			// take the modulus (remainder) to get the last 2 digits
			value = line % 100;
			// pass it in
			RAM.SetAddress(address, value);
		}
		catch (std::invalid_argument e)
		{
			std::cout << "\n*Unable to convert to integer*\n";
		}
	}
}

void CommandShell::RunFromMem(Memory RAM)
{
	int value, command, operand;
	for(int i = 0; i < 100; i++)
	{
		value = RAM.GetAddress(i);
		// divide line by 100 to get first 2 digits
		command = value / 100;
		// take the modulus (remainder) to get the last 2 digits
		operand = value % 100;
		// this is a planning section for the language assignment
		//todo: create functions for math
		/*if (command == 10)
		{
			if (operand == 09)
			{
				Do Something
			}
		}*/
	}
}

void CommandShell::ConfirmClose()
{
	std::string confirm;
	// ask the user to make sure
	std::cout << "\nAre you sure you want to shut down the computer? Y/N\n";
	// gather answer
	std::cin >> confirm;

	// is it yes or no?
	if (confirm == "Y" || confirm == "y")
	{
		// close the program
		exit(0);
	}
	else if (confirm == "N" || confirm == "n")
	{
		// todo: this feels clunky, sharpen up somehow?
	}

}




