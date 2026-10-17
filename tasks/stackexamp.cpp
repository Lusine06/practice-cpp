// stack,queue,deque
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>

int main() {
    // 1. std::stack (LIFO - Last In, First Out)
    std::cout << "stack example \n" ;
    std::stack<int> myStack;

    std::cout << "Enter 3 numbers to push into the stack:\n";
    for (int i = 0; i < 3; ++i) {
        int val;
        std::cout << "Number " << (i + 1) << ": ";
        std::cin >> val;
        myStack.push(val); // Add element to the top
    }

    std::cout << "Top element (top): " << myStack.top() << std::endl;

    myStack.pop(); // Remove the top element
    std::cout << "After pop(), the new top element is: " << myStack.top() << "\n";


    // 2. std::queue (FIFO - First In, First Out)
    std::cout << "queue example \n ";
    std::queue<std::string> myQueue;

    std::cout << "Enter 3 names to add to the queue:\n";
    for (int i = 0; i < 3; ++i) {
        std::string name;
        std::cout << "Name " << (i + 1) << ": ";
        std::cin >> name;
        myQueue.push(name); // Add element to the back
    }

    std::cout << "Front element " << myQueue.front() << std::endl;
    std::cout << "Back element" << myQueue.back() << std::endl;

    myQueue.pop(); // Remove the front element
    std::cout << "After pop(), the new front element is: " << myQueue.front() << "\n\n";


    // 3. std::deque (Double-ended Queue)
    std::cout << "deque example \n";
    std::deque<int> myDeque;

    std::cout << "Enter 2 numbers to add to the front and back of the deque:\n";
    int frontVal, backVal;
    
    std::cout << "Enter value for push_front: ";
    std::cin >> frontVal;
    myDeque.push_front(frontVal); // Add to the front

    std::cout << "Enter value for push_back: ";
    std::cin >> backVal;
    myDeque.push_back(backVal);   // Add to the back

    std::cout << "Deque elements by index:\n";
    for (size_t i = 0; i < myDeque.size(); ++i) {
        std::cout << "Element " << i << ": " << myDeque[i] << std::endl;
    }

    // Removing elements
    myDeque.pop_front();
    myDeque.pop_back();
    std::cout << "Deque size after popping: " << myDeque.size() << std::endl;

    return 0;
}