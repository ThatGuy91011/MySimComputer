#pragma once
#include "Memory.h"
#include <string>

class CommandShell
{
public:
	void IntakeCommand(std::string input, Memory RAM);

private:
	void ProcessCommand(std::string command, Memory RAM);
	void DisplayHelp();
	void DisplayMem(Memory RAM);
	void LoadIntoMem(Memory RAM);
	void RunFromMem(Memory RAM);
	void ConfirmClose();
};

