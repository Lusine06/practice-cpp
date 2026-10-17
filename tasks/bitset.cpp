#include <iostream>
#include <bitset>

int main() {
    // Create an 8-bit bitset, initialized to all 0s
    std::bitset<8> bits; 

    bits.set(0); // Set the 0th bit to 1 -> 00000001
    bits.set(3); // Set the 3rd bit to 1 -> 00001001

    std::cout << "Bitset: " << bits << std::endl; // Prints: 00001001
    std::cout << "Number of 1s: " << bits.count() << std::endl; // Count the number of 1s (2)

    if (bits.test(3)) {
        std::cout << "Bit at index 3 is 1!\n";
    }

    bits.flip(); // Flip all bits (0 -> 1, 1 -> 0)
    std::cout << "After flip: " << bits << std::endl;

    return 0;
}