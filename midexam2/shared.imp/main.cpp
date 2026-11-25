#include <iostream>
#include <utility>
#include "shared_ptr.h"

int main()
{
    SharedPtr<int> p1;
    SharedPtr<int> p2 = new int(100);

    std::cout << "P1's use_count() = " << p1.use_count() << "\n";
    std::cout << "P2's use_count() = " << p2.use_count() << "\n";
    std::cout << "P2's value = " << *p2 << '\n';

    SharedPtr<int> p3 = p2;

    std::cout << "P2 count = " << p2.use_count() << '\n';
    std::cout << "P3 count = " << p3.use_count() << '\n';
    std::cout << "P3 value = " << *p3 << '\n';

    SharedPtr<int> p4;
    p4 = p2;

    std::cout << "P2 count = " << p2.use_count() << '\n';
    std::cout << "P4 count = " << p4.use_count() << '\n';
    std::cout << "P4 value = " << *p4 << '\n';

    SharedPtr<int> p5 = std::move(p2);

    std::cout << "P2 count = " << p2.use_count() << '\n';
    std::cout << "P5 count = " << p5.use_count() << '\n';
    std::cout << "P5 value = " << *p5 << '\n';

    SharedPtr<int> p6;
    p6 = std::move(p5);

    std::cout << "P5 count = " << p5.use_count() << '\n';
    std::cout << "P6 count = " << p6.use_count() << '\n';
    std::cout << "P6 value = " << *p6 << '\n';

    p6.reset(new int(200));
    std::cout << *p6 << " " << p6.use_count() << '\n';

    SharedPtr<int> p7(new int(300));

    p6.swap(p7);

    std::cout << *p6 << '\n';
    std::cout << *p7 << '\n';

    p6 = nullptr;

    std::cout << p6.use_count() << '\n';
    std::cout << (p6.get() == nullptr) << '\n';

    SharedPtr<int> p8;
    SharedPtr<int> p9(new int(50));

    std::cout << (bool)p8 << '\n';
    std::cout << (bool)p9 << '\n';

    SharedPtr<int> p11(new int(100));

    p11 = p11;

    std::cout << *p11 << '\n';
    std::cout << p11.use_count() << '\n';

    // SharedPtr<int> a(new int(10));
    // SharedPtr<int> b = a;

    // a.reset(new int(20));

    // std::cout << *a << '\n';
    // std::cout << *b << '\n';
    // std::cout << a.use_count() << '\n';
    // std::cout << b.use_count() << '\n';

    SharedPtr<int> a(new int(10));

    a.reset();

    std::cout << a.use_count() << '\n';
    std::cout << (a.get() == nullptr) << '\n';

}