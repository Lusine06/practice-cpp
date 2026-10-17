// Usual Fibonacci's function (Running-time)
#include <iostream>
int Fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int n;
    std::cout << "enter the number: ";
    std::cin >> n;

    std::cout << "Fibonacci number is: " << Fibonacci(n) << std::endl;

    return 0;
}


//Compile_time  with consexr

template <int N>
constexpr int fibonacci()
{
    if constexpr (N <= 1)
        return N;
    else
        return fibonacci<N - 1>() + fibonacci<N - 2>();
}

int main()
{
    std::cout << fibonacci<8>() << '\n';
    return 0;
}

// without constexpr

#include <iostream>

template<int N>
int Fibonacci()
{
    return Fibonacci<N - 1>() + Fibonacci<N - 2>();
}

template<>
int Fibonacci<0>()
{
    return 0;
}

template<>
int Fibonacci<1>()
{
    return 1;
}

template<>
int Fibonacci<2>()
{
    return 1;
}

int main()
{
    std::cout << Fibonacci<0>() << '\n';
    std::cout << Fibonacci<3>() << '\n';
    std::cout << Fibonacci<5>() << '\n';
    std::cout << Fibonacci<10>() << '\n';

    return 0;
}