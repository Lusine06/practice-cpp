//Implementation of an unbalanced binary search tree
#include <iostream>

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *removeNode(Node *curr, int val)
    {
        if (curr == nullptr)
            return nullptr;

        if (val < curr->data)
        {
            curr->left = removeNode(curr->left, val);
        }
        else if (val > curr->data)
        {
            curr->right = removeNode(curr->right, val);
        }
        else
        {
            // Node has no children
            if (curr->left == nullptr &&
                curr->right == nullptr)
            {
                delete curr;
                return nullptr;
            }

            // Node has no left child
            if (curr->left == nullptr)
            {
                Node *temp = curr->right;
                delete curr;
                return temp;
            }

            // Node has no right child
            if (curr->right == nullptr)
            {
                Node *temp = curr->left;
                delete curr;
                return temp;
            }

            // Node has two children
            Node *temp = curr->right;

            while (temp->left != nullptr)
                temp = temp->left;

            curr->data = temp->data;
            curr->right = removeNode(curr->right, temp->data);
        }

        return curr;
    }

    void destroyTree(Node *curr)
    {
        if (curr == nullptr)
            return;

        destroyTree(curr->left);
        destroyTree(curr->right);

        delete curr;
    }

public:
    BST() : root(nullptr) {}

    ~BST()
    {
        destroyTree(root);
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *curr = root;

        while (true)
        {
            if (val < curr->data)
            {
                if (curr->left == nullptr)
                {
                    curr->left = newNode;
                    return;
                }

                curr = curr->left; // if not nullptr,go down one level
            }
            else if (val > curr->data)
            {
                if (curr->right == nullptr)
                {
                    curr->right = newNode;
                    return;
                }

                curr = curr->right;
            }
            else
            {
                delete newNode;
                return;
            }
        }
    }

    bool search(int val)
    {
        Node *curr = root;

        while (curr != nullptr)
        {
            if (val == curr->data)
                return true;

            if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        return false;
    }

    void remove(int val)
    {
        root = removeNode(root, val);
    }
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << tree.search(40) << '\n'; // 1 (true)
    std::cout << tree.search(90) << '\n'; // 0 (false)

    tree.remove(20);
    tree.remove(30);
    tree.remove(50);

    std::cout << tree.search(20) << '\n'; // 0 (false)
    std::cout << tree.search(60) << '\n'; // 1 (true)

    return 0;
}