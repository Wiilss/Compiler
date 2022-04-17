#pragma once
#include <string>
#include <vector>
#include <iosfwd>
#include "Operator.h"

#define TOKEN_WHITESPACE_STRING "undefined"

#define INRANGE(value, low, high) (value>=low && value <= high)
#define INBETWEEN(value, low, high) (value>low && value < high)
#define TOKEN(Token) (Token==Token_t::INTEGERLITERAL?"integer_literal":Token==Token_t::STRINGLITERAL?"string_literal":Token==Token_t::OPERATOR?"operator":Token==Token_t::IDENTIFIER?"identifier":Token==Token_t::WHITESPACE?TOKEN_WHITESPACE_STRING:Token==Token_t::OPEN_BRACKET?"open_bracket":Token==Token_t::CLOSE_BRACKET?"close_bracket":Token==Token_t::END_ARG?"end_argument":Token==Token_t::KEYWORD?"keyword":"end_of_command")
#define TOKEN_S(Token) std::string(TOKEN(Token))

#define PUSH_PREV(RESET) { \
	if (CurrentToken != "") {\
		TokenizedString->Tokens.push_back(Token(CurrentToken, ExpectedType, {line, character-CurrentToken.size(), File})); \
		CurrentToken.clear(); \
		ExpectedType = RESET;\
	}\
}nullptr
#define PUSH_PREV_T(TOKEN_TYPE, RESET) {\
	if (CurrentToken != "") {\
		TokenizedString->Tokens.push_back(Token(CurrentToken, TOKEN_TYPE, {line, character-CurrentToken.size(), File})); \
		CurrentToken.clear(); \
		ExpectedType = RESET;\
	}\
}nullptr
#define PUSH_PREV_NS(TOKEN_TYPE, RESET) {\
	TokenizedString->Tokens.push_back(Token( CurrentToken, TOKEN_TYPE, {line, character-CurrentToken.size(), File} )); \
	CurrentToken.clear(); \
	ExpectedType = RESET;\
}nullptr

#define TYPE_KEYWORDS "const", "static", "unsigned", "signed", "void", "int", "char", "long", "short"

static std::string GUCCOperators = "=$^*/+-><!&.", FollowerOperators = "=+-><&";
static std::vector<std::string> TypeKeywords = { TYPE_KEYWORDS };
static std::vector<std::string> GUCCKeywords = {
	"if", "else", "while",
	TYPE_KEYWORDS,
	"struct", "typedef",
	"true", "false",
	"sizeof",
	"__decl", "return",
	"__asm", "__stalloc"
};

enum class Token_t {
	INTEGERLITERAL,
	STRINGLITERAL,
	KEYWORD,
	OPERATOR,
	IDENTIFIER,
	WHITESPACE,
	OPEN_BRACKET,
	CLOSE_BRACKET,
	END_ARG,
	ENDOFCOMMAND
};
std::ostream& operator<<(std::ostream& OutputBuffer, const Token_t& TokenType);

class gcProgram;
struct OPREATOR;

struct ProgramLocation { size_t line, character; std::string File; };

class Token {
public:
	std::string Data;
	Token_t TokenType;
	ProgramLocation Location;
	bool IsDataType;
	OPERATOR Operator;
	void* exData;
	bool Register = 0;
	Token(const std::string& pData, const Token_t& pTokenType, const ProgramLocation& pLocation, bool pDataType = 0, const OPERATOR& pOperator = OPERATOR::opNULL);
	Token(const std::string& pData);
	Token();

	static Token RegisterToken(const std::string& pData, const Token_t& pTokenType, const ProgramLocation& pLocation, bool pDataType = 0, const OPERATOR& pOperator = OPERATOR::opNULL);
	static Token RegisterToken(const std::string& pData);

private:
};

class TokenList {
public:
	std::vector<Token> Tokens;
	operator std::vector<Token>&() { return Tokens; }
	operator std::vector<Token>() const { return Tokens; }
private:

};

void TokenizeString(gcProgram* Program, std::string File = "", std::vector<std::string>* ProgramLog = 0);

OPERATOR EvaluateOperator(const std::vector<Token>::iterator& tIterator);