#include <iostream>
#include <memory>

int main()
{
    auto ptr1 = std::make_shared<int>(200);
    auto ptr2 = ptr1;
    auto ptr3 = ptr1;
    std::cout << "Refcount: " << ptr1.use_count() << '\n';
    {
        auto ptr4 = ptr1;
        std::cout << "Refcount in the scope: " << ptr1.use_count() << '\n';
    }
    ptr2.reset();
    if (ptr2 == nullptr)
        std::cout << "ptr2 = nullptr \n";
    std::cout << "Refcount after scope: " << ptr1.use_count() << '\n';
    std::cout << "*ptr1 = " << *ptr3 << '\n';
    return 0;
}