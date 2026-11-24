
#include "string.hpp"

int main()
{
    std::cout << "Small buffer \n";
    String s1("Hello");
    s1.print();
    std::cout << "size: " << s1.size() << ", capacity: " << s1.capacity() << "\n\n";

    std::cout << "Exactly 22 characters \n";
    String s22("1234567890123456789012");
    s22.print();
    std::cout << "size: " << s22.size() << ", capacity: " << s22.capacity() << "\n\n";

    std::cout << "heap \n";
    String s_large("123456789012345678901234567");
    s_large.print();
    std::cout << "size: " << s_large.size() << ", capacity: " << s_large.capacity() << "\n\n";

    std::cout << "Small -> Heap \n";
    s22.push_back('!');
    s22.print();
    std::cout << "size: " << s22.size() << ", capacity: " << s22.capacity() << "\n\n";

    std::cout << " Small -> Heap \n";
    String s_add(" , adding new words to show the result \n");
    s1.append(s_add);
    s1.print();
    std::cout << "size: " << s1.size() << ", capacity: " << s1.capacity() << "\n\n";

    std::cout << "Large -> Small \n";
    String s_short("tiny");
    s_large = s_short;
    s_large.print();
    std::cout << "size: " << s_large.size() << ", capacity: " << s_large.capacity() << "\n\n";

    std::cout << "Small -> Large \n";
    String s_another_large("randomforexperiment123456789876541");
    s_short = s_another_large;
    s_short.print();
    std::cout << "size: " << s_short.size() << ", capacity: " << s_short.capacity() << "\n\n";

    String s_moved(std::move(s_short));
    std::cout << "moved: ";
    s_moved.print();
    std::cout << "moved size: " << s_moved.size() << ", capacity: " << s_moved.capacity() << "\n";

    std::cout << "source after move -> empty: " << s_short.empty()
              << ", size: " << s_short.size()
              << ", capacity: " << s_short.capacity() << "\n";

    s_moved.clear();
    s_moved.push_back('A');
    std::cout << "after clear + push_back";
    s_moved.print();
    std::cout << "size: " << s_moved.size() << ", capacity: " << s_moved.capacity() << "\n\n";

    std::cout << "COW \n";
    String a("this is a long string which will be on the heap");
    String b(a);
    std::cout << "shared pointer: " << (a.c_str() == b.c_str())
              << "count: " << a.use_count() << "\n";

    b.push_back('!');
    std::cout << " after push, shared pointer: " << (a.c_str() == b.c_str())
              << "count: " << a.use_count() << "\n";
    a.print();
    b.print();

    String c = a;
    c[0] = 'T';
    a.print();
    c.print();

    a.append(a);
    a.print();

    String d = a;
    d.clear(); 
    std::cout << "a size after d.clear(): " << a.size() << ", d size: " << d.size() << "\n";

    std::vector<String> v;
    for (int i = 0; i < 100; i++)
        v.push_back(a);
    std::cout << "vector: a.count = " << a.use_count() << "\n";

    std::cout << "sizeof(String) = " << sizeof(String) << "\n";

    return 0;
}
