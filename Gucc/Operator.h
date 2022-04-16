#pragma once
#include <iosfwd>
#include <string>

#define OPERATOR_LIST \
opPostfixIncrement,\
opPostfixDecrement,\
opFunctionalCast,\
opFunctionCall,\
opSubscript,\
opMemberAccess,\
opDerefMemberAccess,\
\
opPrefixIncrement,\
opPrefixDecrement,\
opUnaryPlus,\
opUnaryMinus,\
opLogicalNOT,\
opBitwiseNOT,\
opCast,\
opDereference,\
opAddressof,\
\
opMultiplication,\
opDivision,\
opRemainder,\
\
opAddition,\
opSubtraction,\
\
opLeftShift,\
opRightShift,\
\
opThreeWayCmp,\
\
opLessThan,\
opLessThanEqual,\
opMoreThan,\
opMoreThanEqual,\
\
opEqualTo,\
opNotEqualTo,\
\
opBitwiseAND,\
\
opBitwiseXOR,\
\
opBitwiseOR,\
\
opLogicalAND,\
\
opLogicalOR,\
\
opDirectAssignment,\
opAdditionAssign,\
opSubtractAssign,\
opMultiAssign,\
opDivideAssign,\
opRemainderAssign,\
opLeftShiftAssign,\
opRightShiftAssign,\
opBitwiseANDAssign,\
opBitwiseXORAssign,\
opBitwiseORAssign,\
\
opComma,\
\
opNULL

class Token;

enum class _Associativity {
	aLeftToRight,
	aRightToLeft
};

enum class OPERATOR_ID {
	OPERATOR_LIST
};

struct OPERATOR {
	_Associativity Associativity;
	size_t Precedence;
	OPERATOR_ID OperatorID;
	const static OPERATOR OPERATOR_LIST;
};



bool operator==(const OPERATOR& OperatorLeft, const OPERATOR& OperatorRight);
bool operator!=(const OPERATOR& OperatorLeft, const OPERATOR& OperatorRight);

const bool ArithmeticOperator(const OPERATOR& Operator);