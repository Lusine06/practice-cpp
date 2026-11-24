#include <iostream>
#include <memory>

int main()
{
    auto ptr1 = std::make_unique<int>(100);
    std::cout << "*ptr1 = " << *ptr1 << '\n';
    auto ptr2 = std::move(ptr1);
    if (ptr1 == nullptr)
        std::cout << "The ownership was changed \n";
    else
        std::cout << "The ownwership didn't change \n";
    std::cout << "*ptr2 = " << *ptr2 << '\n';
    return 0;
}