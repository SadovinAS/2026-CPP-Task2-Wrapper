#include "strchanger.h"

std::string StringChanger::Replace(const std::string& From, const std::string& Tor) {
	std::string MainStr(Str);
	if (MainStr.empty()) {
		return "";
	}
	std::size_t pos;
	while ((pos = MainStr.find(From)) != std::string::npos) {
		MainStr.replace(pos, From.length(), Tor);
	}
	return MainStr;
}
bool StringChanger::Find(const std::string& What) {
	if (Str.empty()) {
		return false;
	}
	return Str.find(What) != std::string::npos;
}
std::string StringChanger::CapitalizeWords() {
	std::string MainStr(Str);
	if (MainStr.empty()) {
		return "";
	}
	if (std::isalpha(MainStr[0]) != 0) {
		MainStr[0] = static_cast<char>(std::toupper(MainStr[0]));
	}
	for (std::size_t i = 0; i < MainStr.size() - 1; i++) {
		if ((std::isspace(MainStr[i]) != 0 || std::ispunct(MainStr[i]) != 0) && std::isalpha(MainStr[i + 1]) != 0){
			MainStr[i + 1] = static_cast<char>(std::toupper(MainStr[i + 1]));
		}
	}
	return MainStr;
}
std::string StringChanger::CapitalizeSentences() {
	std::string MainStr(Str);
	if (MainStr.empty()) {
		return "";
	}
	bool newSent = true;
	for (char &c : MainStr) {
		if (std::isalpha(c) != 0 && newSent) {
			MainStr[i] = static_cast<char>(std::toupper(c));
			newSent = false;
		}
		else if (c == '.' || c == '!' || c == '?') {
			newSent = true;
		}
	}
	return MainStr;
}
std::string StringChanger::NumberSentences() {
	std::string MainStr(Str);
	if (MainStr.empty()) {
		return "";
	}
	bool newSent = false;
	int counter = 1;
	MainStr.insert(0, "1. ");
	for (std::size_t i = 4; i < MainStr.size(); i++) {
		if (std::isalpha(MainStr[i]) != 0 && newSent) {
			std::string csim = std::to_string(++counter) + ". ";
			MainStr.insert(i, csim);
			i += csim.length();
			newSent = false;
		}
		else if (MainStr[i] == '.' || MainStr[i] == '!' || MainStr[i] == '?') {
			newSent = true;
			while (std::isspace(MainStr[i + 1]) != 0) {
				i++;
			}
			MainStr.insert(i + 1, "\n");
			i++;
		}
	}
	return MainStr;
}