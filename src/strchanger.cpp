#include "strchanger.h"

std::string StringChanger::Replace(std::string MainStr, const std::string& From, const std::string& Tor) {
	if (MainStr.empty()) {
		return "";
	}
	int pos;
	while ((pos = MainStr.find(From)) != std::string::npos) {
		MainStr.replace(pos, From.length(), Tor);
	}
	return MainStr;
}
bool StringChanger::Find(const std::string &MainStr, const std::string& What) {
	if (MainStr.empty()) {
		return false;
	}
	return MainStr.find(What) != std::string::npos;
}
std::string StringChanger::CapitalizeWords(std::string MainStr) {
	if (MainStr.empty()) {
		return "";
	}
	if (std::isalpha(MainStr[0])) {
		MainStr[0] = std::toupper(MainStr[0]);
	}
	for (int i = 0; i < MainStr.size() - 1; i++) {
		if ((std::isspace(MainStr[i]) || std::ispunct(MainStr[i]))){
			if (std::isalpha(MainStr[i + 1])) {
				MainStr[i + 1] = std::toupper(MainStr[i + 1]);
			}
		}
	}
	return MainStr;
}
std::string StringChanger::CapitalizeSentences(std::string MainStr) {
	if (MainStr.empty()) {
		return "";
	}
	bool newSent = true;
	for (int i = 0; i < MainStr.size(); i++) {
		if (std::isalpha(MainStr[i]) && newSent) {
			MainStr[i] = std::toupper(MainStr[i]);
			newSent = false;
		}
		else if (MainStr[i] == '.' || MainStr[i] == '!' || MainStr[i] == '?') {
			newSent = true;
		}
	}
	return MainStr;
}
std::string StringChanger::NumberSentences(std::string MainStr) {
	if (MainStr.empty()) {
		return "";
	}
	bool newSent = false;
	int counter = 1;
	MainStr.insert(0, "1. ");
	for (int i = 4; i < MainStr.size(); i++) {
		if (std::isalpha(MainStr[i]) && newSent) {
			std::string csim = std::to_string(++counter) + ". ";
			MainStr.insert(i, csim);
			i += csim.length();
			newSent = false;
		}
		else if (MainStr[i] == '.' || MainStr[i] == '!' || MainStr[i] == '?') {
			newSent = true;
			while (std::isspace(MainStr[i + 1])) {
				i++;
			}
			MainStr.insert(i + 1, "\n");
			i++;
		}
	}
	return MainStr;
}