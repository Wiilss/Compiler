#pragma once
#include <string>

class gcProgram;



void Preprocessor(gcProgram* Program, std::vector<std::string>* IncludedFiles);
void ImplementPreprocessorMacros(gcProgram* Program);
void ParseProgram(gcProgram* Program, std::vector<std::string>* ProgramLog);
int FunctionSignatures(gcProgram* Program, std::vector<std::string>* ProgramLog);
int SyntaxCheck(gcProgram* Program, std::vector<std::string>* ProgramLog);

void sReplace(std::string& string, const std::string& StringToReplace, const std::string& StringToReplaceWith);


struct FunctionSignature {
	std::string Name;
	std::vector<Token> ReturnType;
	size_t ArgumentCount;
	std::vector<Token> FunctionBody;
	std::vector<Token> Arguments;
	ProgramLocation Location;
};