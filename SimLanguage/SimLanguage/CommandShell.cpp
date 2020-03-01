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

void CommandShell::ProcessCommand(std::string command, Memory& RAM)
{
	// check the input and launch appropriate section
	if (command == "Help")
	{
		// launch display help function
		DisplayHelp();
	}
	else if (command == "DisplayMem")
	{
		// launch display memory function
		DisplayMem(RAM);
	}
	else if (command == "Load")
	{
		// launch memory loader function
		LoadIntoMem(RAM);
	}
	else if (command == "Run")
	{
		// start and run the code
		RunFromMem(RAM);
	}
	else if (command == "Exit")
	{
		// exit the shell - shutdown the sim computer
		ConfirmClose();
	}
	else
	{
		// give an error to the user
		// std::cout << "\n*Unknown Command*\n";
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

	int lineCounter = 0;
	// read the lines of the file
	while (std::getline(file, word))
	{

		// try catch to conver string to int
		try
		{
			// String To Int
			line = std::stoi(word);
			// divide line by 100 to get first 2 digits
			address = line / 100;
			// take the modulus (remainder) to get the last 2 digits
			value = line % 100;
			// pass it in
			RAM.SetAddress(lineCounter, line);
			// add to counter
			lineCounter++;
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
	while (instructionPointer < 100)
	{

		value = RAM.GetAddress(instructionPointer);
		// divide line by 100 to get first 2 digits
		command = value / 100;
		// take the modulus (remainder) to get the last 2 digits
		operand = value % 100;

		//print screen
		if (command == 10)
		{
			// console out
			std::cout << accumulator << std::endl;
		}
		// load from mem to accum
		else if (command == 20)
		{
			accumulator = operand;
		}
		// load to mem from accum
		else if (command == 21)
		{
			RAM.SetAddress(instructionPointer, (command + accumulator));
		}
		// add
		else if (command == 30)
		{
			accumulator += operand;
		}
		// subtract
		else if (command == 31)
		{
			accumulator -= operand;
		}
		// multiply
		else if (command == 32)
		{
			accumulator = accumulator * operand;
		}
		// divide
		else if (command == 33)
		{
			accumulator = accumulator / operand;
		}
		// modulus
		else if (command == 34)
		{
			accumulator = accumulator % operand;
		}
		// jump to location
		else if (command == 40)
		{
			instructionPointer = operand;
		}
		// jump to location if accum is greater
		else if (command == 41)
		{
			if (accumulator > operand)
			{
				instructionPointer = operand;
			}
		}
		// jump to location if accum is less
		else if (command == 42)
		{
			if (accumulator < operand)
			{
				instructionPointer = operand;
			}
		}
		// jump to location if accum is 0
		else if (command == 43)
		{
			if (accumulator == 0)
			{
				instructionPointer = operand;
			}
		}
		// jump to location if accum equals operand
		else if (command == 44)
		{
			if (accumulator == operand)
			{
				instructionPointer = operand;
			}
		}
		instructionPointer++;
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
		return;
	}

}
