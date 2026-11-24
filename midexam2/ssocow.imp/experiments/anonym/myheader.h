#pragma once
#include <iostream>

namespace {
    int number = 10;

    void foo() {
        std::cout << "Hello from foo()\n";
    }

    class MyClass {
    public:
        void print() {
            std::cout << "Hello from MyClass\n";
        }
    };
}