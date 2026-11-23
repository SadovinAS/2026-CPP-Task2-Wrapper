#pragma once
#include <string>

class StringChanger {
public:
	std::string Replace(std::string MainStr, const std::string& From, const std::string& To);
	bool Find(const std::string& MainStr, const std::string& What);
	std::string CapitalizeWords(std::string MainStr);
	std::string CapitalizeSentences(std::string MainStr);
	std::string NumberSentences(std::string MainStr);
};