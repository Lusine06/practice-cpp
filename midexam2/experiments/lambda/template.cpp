#include <iostream>
#include <iostream>
// #include <boost/type_index.hpp>

template <typename T>
void foo(T &t)
{
    using boost::typeindex::type_id_with_cvr;

    std::cout << "T type: "
              << type_id_with_cvr<T>().pretty_name() << '\n';

    std::cout << "t type: "
              << type_id_with_cvr<decltype(t)>().pretty_name() << '\n';

    std::cout << "t value: " << t << '\n';

}

int main()
{
    int x = 10;
    const int cx = 20;
    volatile int vx = 30;

    int *p = &x;
    const int *cp = &x;
    int *const pc = &x;

    foo(x);
    foo(cx);
    foo(vx);

    foo(p);
    foo(cp);
    foo(pc);
}