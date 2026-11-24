//1st
#include <iostream>

// int main() {
//     try {
//         throw 10;
//     }
//     catch (int x) {
//         std::cout << "First catch: " << x << '\n';
//         throw; 
//     }
// }

// Firts catch: 10
// terminate called after throwing an instance of 'int'


//2nd

// int main() {
//     try {
//         try {
//             throw 10;
//         }
//         catch (int x) {
//             std::cout << "First catch: " << x << '\n';
//             throw;
//         }
//     }
//     catch (int x) {
//         std::cout << "Second catch: " << x << '\n';
//     }
// }

// First catch: 10
// Second catch: 10


// 3rd

int main() {
    try {
        throw 10;
    }
    catch (int x) {
        std::cout << x << '\n';
    }

    throw; 
}


// 10
// terminate called without an active exception