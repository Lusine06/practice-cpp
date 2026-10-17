//passing the argument as a pointer || as a simple value
#include <iostream>

class Pointer
{
private:
    int* ptr;

public:
    explicit Pointer(int value)
    {
        ptr = new int(value);
    }

    explicit Pointer(int* p)
    {
        ptr = p;
    }

    ~Pointer()
    {
        delete ptr;
        ptr = nullptr;
    }

    void reset()
    {
        delete ptr;
        ptr = nullptr;
    }

    int getvalue()
    {
        return *ptr;
    }
};

int main()
{
    Pointer p1(10);
    std::cout << "p1 value: " << p1.getvalue() << std::endl;

    int* raw_ptr = new int(25);
    Pointer p2(raw_ptr);
    std::cout << "p2 value: " << p2.getvalue() << std::endl;

    p1.reset();
    std::cout << "p1 is reset." << std::endl;

    return 0;
}