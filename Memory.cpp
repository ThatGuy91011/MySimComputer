#include "Memory.h"
#include <iostream>


void Memory::SetAddress(int address, int value)
{
	// check to make sure address is in range
	if (address >= 0 && address <= 99)
	{
		// check is in the load memory function
		// should I include another check?
		memAddress[address] = value;
	}
	else
	{
		throw;
	}
	
}

int Memory::GetAddress(int address)
{
	return memAddress[address];
}
