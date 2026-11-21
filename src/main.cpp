#include <iostream>
#include <string>
#include "wrapper.h"

class Sum {
public:
    int s = 0;

    Sum(int c) : s(c) {}
    int add(int a, int b) {
        s += a += b;
        return s;
    }
    int var(const std::string& name, double value) {
        std::cout << name << " -> " << value << '\n';
        return 0;
    }
};


int main(){
    std::cout << "Hello Wrapper!\n";
    std::cout << "Hello Engine!\n";

    Sum S(5);

    Wrapper wrapper_add(&S, &Sum::add, { {"arg1", 4}, {"arg2", 2} });
    Wrapper wrapper_var1(&S, &Sum::var, { {"arg1", std::string("A")}, {"arg2", 0.0} });
    Wrapper wrapper_var2(&S, &Sum::var, { {"arg1", std::string("B")}, {"arg2", 5.0} });

    Engine engine;
    engine.add(&wrapper_add, "func1");
    engine.add(&wrapper_var1, "func2");
    engine.add(&wrapper_var2, "func3");

    std::cout << engine.execute("func1") << std::endl;
    engine.execute("func2");
    engine.execute("func3");
    return 0; 
}