#include <iostream>
#include <string>
#include "wrapper.h"
#include "engine.h"
#include "strchanger.h"

int main(){
    StringChanger StrCh;

    Wrapper wrapper_Find(&StrCh, &StringChanger::Find, { {"arg1", std::string("MainStr place here, it is placeholder")}, {"arg2",  std::string("it is")}});
    Wrapper wrapper_Replace(&StrCh, &StringChanger::Replace, { {"arg1", std::string("MainStr place here, it is placeholder")}, {"arg2",  std::string("MainStr")}, {"arg3",  std::string("NewStr")} });
    Wrapper wrapper_CapWords(&StrCh, &StringChanger::CapitalizeWords, { {"arg1", std::string("MainStr place here, it is placeholder")} });
    Wrapper wrapper_CapSens(&StrCh, &StringChanger::CapitalizeSentences, { {"arg1", std::string("MainStr place here, it is placeholder")} });
    Wrapper wrapper_NumSens(&StrCh, &StringChanger::NumberSentences, { {"arg1", std::string("MainStr place here, it is placeholder")} });

    Engine engine;
    engine.register_command(&wrapper_Find, "find");
    engine.register_command(&wrapper_Replace, "replace");
    engine.register_command(&wrapper_CapWords, "capwords");
    engine.register_command(&wrapper_CapSens, "capsens");
    engine.register_command(&wrapper_NumSens, "numsens");

    std::string TestStr("lorem ipsum dolor sit amet, consectetur adipiscing elit. sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    
    std::cout << engine.execute("find", { { "arg1", TestStr}, {"arg2", std::string("ut labore et")}}) << std::endl << std::endl;
    std::cout << engine.execute("replace", { { "arg1", TestStr}, {"arg2", std::string("molit")}, {"arg3", std::string("ne molit")} }) << std::endl << std::endl;
    std::cout << engine.execute("capwords", { { "arg1", TestStr} }) << std::endl << std::endl;
    std::cout << engine.execute("capsens", { { "arg1", TestStr} }) << std::endl << std::endl;
    std::cout << engine.execute("numsens", { { "arg1", TestStr} }) << std::endl << std::endl;
    return 0; 
}