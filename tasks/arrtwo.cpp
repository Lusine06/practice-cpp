///* Array,where each element repeats twice,besides two elements,find extra ones.*/
#include <iostream>

int main()
{
    int array[] = {4, 1, 7, 9, 4, 6, 2, 1,
                   8, 7, 6, 2, 9, 8, 3, 5};

    int n = sizeof(array) / sizeof(array[0]);

    int result = 0;

    //  XOR all elements
    for (int i = 0; i < n; i++)
        result ^= array[i];

    // result = 3 ^ 5  -> 011 ^ 101 -> 110 (we got 1 in the places where the numbers are different) 

    //  find one bit where 3 and 5 are different 
    int bit = result & (-result);

    int first = 0;
    int second = 0;

    //  divide numbers into two groups
    for (int i = 0; i < n; i++)
    {
        if (array[i] & bit)
            first ^= array[i];
        else
            second ^= array[i];
    }

    std::cout << "First number: " << first << '\n';
    std::cout << "Second number: " << second << '\n';

    return 0;
}  // O(n)