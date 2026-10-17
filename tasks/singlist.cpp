//  singly list implementation

#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // faster because  data --> construct
};

class LinkedList
{
private:
    Node* head;
    size_t size;

public:
    LinkedList(Node* h, size_t s)
    {
        head = h;
        size = s;
    }

    ~LinkedList()
    {
        clear();
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (head == nullptr) return; // if list is empty..

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void pop_back()
    {
        if (head == nullptr) return; // if list is empty..

        if (head->next == nullptr)  // if list has one element..
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }

        Node* curr = head;
        while (curr->next->next != nullptr) //prelast --> so that we can delete the last one
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;
        size--;
    }

    void print() const //conat --> this method will not modify the class fields.
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    size_t get_size() const
    {
        return size;
    }
};

int main()
{
    LinkedList list(nullptr, 0);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);

    std::cout << "List: ";
    list.print();                 // 5 10 20 30

    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();                 // 10 20 30

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();                 // 10 20

    std::cout << "Size: " << list.get_size() << "\n";   // 2

    return 0;
}

