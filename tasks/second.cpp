// Constructors & destructors order change
//When two objects are in the same scope -> LIFO(Last In,First Out)

#include <iostream>
class A
{
public:
    A()
    {
        std::cout << "A's constructor \n";
    }
    ~A()
    {
        std::cout << "A's destructor \n";
    }
};

class B
{
public:
    B()
    {
        std::cout << "B's constructor \n";
    }
    ~B()
    {
        std::cout << "B's destructor \n";
    }
};

int main()
{
    std::cout << "Start: \n";
    //local scope for A
    {
        A a;
    } // here ends A's scope

    //local scope for B
    {
        B b;
    } // here ends B's scope

    std::cout << "End \n";
    return 0;
}