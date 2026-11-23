#pragma once
#include <string>

class StringChanger {
public:
	static std::string Replace(std::string MainStr, const std::string& From, const std::string& Tor);
	static bool Find(const std::string& MainStr, const std::string& What);
	static std::string CapitalizeWords(std::string MainStr);
	static std::string CapitalizeSentences(std::string MainStr);
	static std::string NumberSentences(std::string MainStr);
};