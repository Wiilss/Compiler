#pragma once
#define _GUCC_22_IMPL_
#include "Program.h"
#include "Tokenizer.h"
#include "Parse.h"
#include <stdexcept>

#define _push(label) __asm {push label}
#define _pop(label) __asm {pop label}

template<typename ... Args>
static inline std::string format_s(const std::string& format, Args ... args) {
	int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1;
	if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
	auto size = static_cast<size_t>(size_s);
	char* buffer = (char*)malloc(size);
	std::snprintf(buffer, size, format.c_str(), args ...);
	std::string string(buffer, buffer + size - 1);
	free(buffer);
	return string; 
}