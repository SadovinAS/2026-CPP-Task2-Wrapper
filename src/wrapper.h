#include <iostream>
#include <string>
#include <map>
#include <any>

class BigWrapper {
public:
	BigWrapper() {}
	virtual std::string Execute() = 0;
};


template <typename SubjectType, typename RetFuncType, typename ...Args>
class Wrapper : public BigWrapper{
public:
	SubjectType* Subject;
	RetFuncType(SubjectType::*SubjectFunc)(Args...);
	std::map<std::string, std::any> ArgList;

	Wrapper(SubjectType* Subj, RetFuncType(SubjectType::*SubjFunc)(Args...), const std::map<std::string, std::any>& List) : Subject(Subj), SubjectFunc(SubjFunc), ArgList(List)
	{}
	
	std::string Execute() override {
		return std::to_string(Execute2(std::index_sequence_for<Args...>()));
	}
	template <std::size_t ...Is>
	RetFuncType Execute2(std::index_sequence<Is...>) {
		std::string arg = "arg";
		return (Subject->*SubjectFunc)(std::any_cast<Args>(ArgList[arg + std::to_string(Is + 1)])...);
	}
};

class Engine {
public:
	std::map < std::string, BigWrapper* > List;
		
	void add(BigWrapper* wrapper, const std::string& command_name) {
		List[command_name] = wrapper;
	}

	std::string execute(std::string command_name) {
		return List[command_name]->Execute();
	}
};