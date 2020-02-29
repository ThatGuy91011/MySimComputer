#include "Processor.h"
#include "Memory.h"
#include <iostream>
#include <string>

Processor::Processor(Memory& _memory) : memory(_memory) {}

void Processor::runProgram(int beginningAddress) {
	instructionPointer = beginningAddress;

	while ((memory.GetAddress(instructionPointer) & OPCODE_MASK) != STOP) {
		FetchInstruction();
		decodeAndExecute();
	}
}

int Processor::FetchInstruction() {
	instruction = memory.GetAddress(instructionPointer);
	instructionPointer++;
	return instruction;
}

void Processor::decodeAndExecute() {
  //using binary
  //Unsigned 8 bit type
	const uint8_t opCode = (uint8_t)(instruction & OPCODE_MASK);
	const uint8_t argument = (uint8_t)(instruction & ARG_MASK);

	switch (opCode) {
		//Prints out instruction
	case PRINT:
		std::cout << memory.GetAddress(argument) << std::endl;
		break;
	default:
		break;
	}
}
