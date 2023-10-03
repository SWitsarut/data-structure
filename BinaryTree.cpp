#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
    }
    Node(Node *left, int data, Node *right)
    {
        this->left = left;
        this->data = data;
        this->right = right;
    }
};
