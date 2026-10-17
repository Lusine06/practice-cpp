#include <iostream>
#include <string>

int main() {
    std::string s = "hi"; //  կարճ տող(SSO opt.)

    // Որտե՞ղ է գտնվում ինքը օբյեկտը (stack-ում)
    std::cout << "Object address (&s): " << &s << std::endl;
    
    //  Որտե՞ղ են գտնվում տառերը ('h' և 'i')
    std::cout << "Data address (s.data()): " << static_cast<const void*>(s.data()) << std::endl;

    return 0;
}