#pragma once
#include "Memory.h"

class Processor
{
private:
	int accumulator;
	int instructionPointer;
	uint16_t instruction;
	//References the memory
	Memory& memory;

	enum INSTRUCTIONS {
		PRINT = 0b00000001,
		LDA,
		STA,
		ADD,
		SUB,
		STOP = 0b11111111
	};
//placements rather than having to write out the binary each time.
	const uint16_t OPCODE_MASK = 0b1111111100000000;
	const uint16_t ARG_MASK = 0b0000000011111111;

public:
	Processor(Memory& _memory);

	//This should return the instruction
	void runProgram(int beginningAddress);
	int FetchInstruction();
	void decodeAndExecute();

};

