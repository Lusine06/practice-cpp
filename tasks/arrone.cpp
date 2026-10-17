/* Array,where each element repeats twice,besides one,find that extra one.*/
#include <iostream>
int main () {
    int array [] = {0, 2, 3, 8, 7, 7, 1, 1, 0, 8, 2};
    int n = sizeof(array) / sizeof(array[0]);
    
    int extra = 0;
    for (int i = 0; i < n; i ++)
        extra ^= array[i];
        
    std::cout << "Single number is: " << extra << std::endl;
    return 0;
}

//why? ^ means XOR.   a XOR a = 0 && a XOR 0 = a