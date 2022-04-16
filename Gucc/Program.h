#pragma once
#include <string>
#include "Tokenizer.h"

#define TYPE(Type) (Type==Type_t::INT8?"char":Type==Type_t::INT16?"short int":Type==Type_t::INT32?"long int":Type==Type_t::INT64?"long long int":"void")
#define TYPE_S(Type) std::string(TYPE(Type))

#define LITERAL(token) (token==Token_t::INTEGERLITERAL||token==Token_t::STRINGLITERAL)

struct FunctionSignature;
class gcProgram;

void GetFile(const std::string& FileName, std::string& string);
std::string GetFile(const std::string& FileName);

void LoadProgram(gcProgram* Program, const std::string& Source);
int CompileProgram(gcProgram* Program, const struct CompilerParameters& cParameters, std::vector<std::string>* ProgramLog);
int LinkProgram(gcProgram* Program, std::vector<gcProgram*>& ProgramLinks);
void CreateProgramLinks(std::vector<gcProgram*>* ProgramLinks, std::vector<std::string>* IncludedFiles);

enum class LinkMethod {
	PushFront,
	PushBack
};

enum class Type_t {
	INT8,
	INT16,
	INT32,
	INT64,
	POINTER,
	VOID
};

class gcProgram {
public:
	TokenList Tokens;
	std::string Source;
	std::vector<FunctionSignature> FunctionSignatures;
	gcProgram();
};

struct Variable {
	std::string Name;
	int StackLocation;
	Type_t VariableType;
	unsigned int Size;
	bool SignBit, Constant;
	unsigned char _pointer;
};


struct Variable_t {
	static const Variable _VOID, _INT8, _INT16, _INT32, _INT64, _CSTRING;
};

struct CompilerParameters {
	bool bConstantFolding = 1, 
		bAssemblyLineComments = 1;
};


bool sVariableCmp(const Variable& VariableLeft, const Variable& VariableRight, const bool AllowEnumeratedTypes = 1);
bool VariableCmp(const Variable& VariableLeft, const Variable& VariableRight, const bool AllowEnumeratedTypes = 1);
bool sizeVariableCmp(const Variable& VariableLeft, const Variable& VariableRight);
bool VariableEnum(const Variable& _Variable);

unsigned int SizeOf(const Type_t& Type);
unsigned int SizeOf(const Variable& variable);


struct Function {
	std::string Name;
	const Variable ReturnType;
	std::vector<Token>& FunctionBody;
	std::vector<Variable> Arguments;
	ProgramLocation Location;
};

