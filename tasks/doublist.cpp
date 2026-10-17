// doubly linked list (pop/push/insert/erase)

#include <iostream>

template <typename T>
class List
{

private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;

        Node(const T &val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List()
    {
        clear();
    }

    void push_back(const T &val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(const T &val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert(const T &val, int pos)
    {
        if (pos < 0)
            return;
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;
        if (curr == nullptr)
            return;
        if (curr->next == nullptr)
        {
            push_back(val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    void pop_back()
    {
        if (tail == nullptr)
            return;

        Node *temp = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }

    void erase(int pos)
    {
        if (pos < 0)
            return;

        if (head == nullptr)
            return;

        if (pos == 0)
        {
            pop_front();
            return;
        }

        Node *curr = head;
        for (int i = 0; i < pos && curr != nullptr; i++)
            curr = curr->next;

        if (curr == nullptr)
            return;

        if (curr->next == nullptr)
        {
            pop_back();
            return;
        }

        Node *prev = curr->prev;
        Node *next = curr->next;

        prev->next = next;
        next->prev = prev;

        delete curr;
    }

    void print() const
    {
        Node *curr = head;
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
            pop_front();
        }
    }

    bool empty() const
    {
        return head == nullptr;
    }
};

int main()
{
    List<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    std::cout << "List elements (after push_back/push_front):\n";
    myList.print();

    myList.insert(100, 2);
    myList.insert(200, 0);

    std::cout << "List elements (after insert):\n";
    myList.print();

    myList.pop_front();
    myList.pop_back();

    std::cout << "List elements (after pop_front/pop_back):\n";
    myList.print();

    myList.erase(0);
    myList.erase(15);  

    std::cout << "List elements (after erase):\n";
    myList.print();


    // empty list test

    List<int> emptyList;
    std::cout << "Empty list test:\n";
    emptyList.print();
    emptyList.pop_front();
    emptyList.pop_back();
    emptyList.erase(0);
    std::cout << "No crash\n";

    return 0;
}