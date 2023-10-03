#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL
{
public:
    Node *root;
    AVL()
    {
        root = nullptr;
    }
    int height(Node *node)
    {
        return node == nullptr ? -1 : node->height;
    }
    int getBf(Node *node)
    {
        return height(node->left) - height(node->right);
    }
    void balance(Node *&node)
    {
        if (node == nullptr)
        {
            return;
        }
        if (getBf(node) > 1)
            if (height(node->left->left) >= height(node->left->right))
                rotateWithLeftChild(node);
            else
                doubleWithRightChild(node);
        else if (height(node->right) - height(node->left) > 1)
            if (height(node->right->right) >= height(node->right->left))
                rotateWithRightChild(node);
            else
                doubleWithLeftChild(node);

        node->height = 1 + max(height(node->left), height(node->right));
    }

    void rotateWithLeftChild(Node *&k2)
    {
        Node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }
    void rotateWithRightChild(Node *&k2)
    {
        Node *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }
    void doubleWithLeftChild(Node *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(Node *&k3)
    {
        rotateWithLeftChild(k3->left);
        rotateWithRightChild(k3);
    }

    void insert(int data, Node *&node)
    {
        if (node == nullptr)
        {
            node = new Node(data);
        }
        else if (data < node->data)
        {
            insert(data, node->left);
        }
        else if (data > node->data)
        {
            insert(data, node->right);
        }
        balance(node); // Call balance after inserting a new node.
    }

    Node *findMin(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr; // Tree is empty.
        }
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void remove(int data, Node *&node)
    {
        if (node == nullptr)
        {
            return;
        }
        if (data < node->data)
        {
            remove(data, node->left);
        }
        else if (node->data < data)
        {
            remove(data, node->right);
        }
        else if (node->left != nullptr && node->right != nullptr)
        {
            node->data = findMin(node->right)->data;
            remove(node->data, node->right);
        }
        else
        {
            Node *oldNode = node;
            if (node->left != nullptr)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
            delete oldNode;
        }
        if (node != nullptr)
        {
            balance(node);
        }
    }

    void preOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main()
{
    AVL *tree = new AVL();
    char op;
    int num;
    do
    {
        cin >> op;
        switch (op)
        {
        case 'a':
            cin >> num;
            tree->insert(num, tree->root);
            break;
        case 'd':
            cin >> num;
            tree->remove(num, tree->root);
            break;
        case 'p':
            tree->preOrder(tree->root);
            cout << endl;
            break;
        }
    } while (op != 'x');

    delete tree;
    return 0;
}
