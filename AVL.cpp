#include <iostream>
#include <algorithm>
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
        this->left = nullptr;
        this->data = data;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVL
{
public:
    Node *root = nullptr;

    Node *search(int data)
    {
        Node *cur = this->root;
        while (cur != nullptr && cur->data != data)
        {
            if (data < cur->data)
            {
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        return cur;
    }
    int getHeight(Node *target)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return target->height;
        }
    }

    int getBalanceFactor(Node *target)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return getHeight(target->left) - getHeight(target->right);
        }
    }

    void updateHeight(Node *target)
    {
        target->height = 1 + max(getHeight(target->left), getHeight(target->right));
    }

    Node *leftRotate(Node *target)
    {
        Node *rightNode = target->right;
        Node *center = rightNode->left;

        rightNode->left = target;
        target->right = center;

        updateHeight(target);
        updateHeight(rightNode);
        return rightNode;
    }

    Node *rightRotate(Node *target)
    {
        // beta
        Node *leftNode = target->left;
        Node *centerNode = leftNode->right;

        leftNode->right = target;
        target->left = centerNode;

        updateHeight(target);
        updateHeight(leftNode);
        return leftNode;
    }

    void insert(int data)
    {
        root = insert(data, root);
    }

    Node *balance(Node *pos)
    {
        int bf = getBalanceFactor(pos);
        if (bf > 1)
        // left heavy
        {
            if (getBalanceFactor(pos->left) < 0)
            {
                pos->left = leftRotate(pos->left);
            }
            return rightRotate(pos);
        }
        if (bf < -1) // right heavy
        {
            if (getBalanceFactor(pos->right) > 0)
            {
                pos->right = rightRotate(pos->right);
            }
            return leftRotate(pos);
        }
        return pos;
    }

    Node *insert(int data, Node *pos)
    {
        if (pos == nullptr)
        {
            cout << "yes";
            return new Node(data);
        }
        if (data < pos->data)
        {
            pos->left = insert(data, pos->left);
        }
        else if (data > pos->data)
        {
            cout << "here";
            pos->right = insert(data, pos->right);
        }
        else
        {
            return pos;
        }
        updateHeight(pos);
        return balance(pos);
    }

    void remove(int data)
    {
        root = remove(data, root);
    }
    int getMax(Node *node)
    {
        if (node != nullptr)
        {
            while (node->right != nullptr)
            {
                node = node->right;
            }
        }
        return node->data;
    }

    Node *remove(int data, Node *pos)
    {
        if (pos == nullptr)
        {
            return nullptr;
        }
        if (data < pos->data)
        {
            pos->left = remove(data, pos->left);
        }
        else if (data > pos->data)
        {
            pos->right = remove(data, pos->right);
        }
        else
        {
            if (pos->left == nullptr)
            {
                Node *temp = pos->right;
                delete pos;
                return temp;
            }
            else if (pos->right == nullptr)
            {
                Node *temp = pos->left;
                delete pos;
                return temp;
            }
            pos->data = getMax(pos->left);
            pos->left = remove(pos->data, pos->left);
        }
        updateHeight(pos);
        return balance(pos);
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
            tree->insert(num);
            break;
        case 'd':
            cin >> num;
            tree->remove(num);
            break;
        case 'p':
            tree->preOrder(tree->root);
        }
    } while (op != 'x');

    delete tree;
    return 0;
}