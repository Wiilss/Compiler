#pragma once
#include <iosfwd>
#include <string>
#include <vector>

struct AssemblyProgram {
	std::string dotCode, dotData, Source;
};

struct FunctionDefinition {
	std::string Name; std::vector<std::string> Body;
};

/*
	store the function address
	store the body address

*/


void asmSetCurrentProgram(AssemblyProgram* const Program);

void asmPushCurrentFunction(const std::string& EndInstruction = "");
void asmAddFunction(const std::string& FunctionName);

void asmCreateAsmSource(void);

void asmPushInstruction(const std::string& Instruction, size_t* PushedAddress = 0, const bool IsLabel = 0);
void asmPushInstructionLabel(const std::string& Instruction, size_t* PushedAddress = 0);
void asmPushInstructionTop(const std::string& Instruction, size_t* PushedAddress = 0);
void asmPushDataInstruction(const std::string& Instruction, size_t* PushedAddress = 0);

void asmWriteInstruction(size_t& InstructionAddress, const std::string& Instruction);
void asmWriteInstructionf(size_t& FunctionAddress, size_t& Address, const std::string& Instruction);
void asmWriteDataInstruction(size_t& InstructionAddress, const std::string& Instruction);

void asmFreeProgram();