#pragma once
class Memory
{
public:
	// getter and setter
	void SetAddress(int address, int value);
	int GetAddress(int address);

private:
	// private array
	int memAddress[100] = { 0 };
	// maybe use string
	// std::string m_memory[100];
};

