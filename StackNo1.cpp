#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int *child;
    bool Error = false;
    Stack()
    {
        size = -1;
        child = new int[100];
    }
    void push(int c)
    {
        size++;
        child[size] = c;
    };
    int pop()
    {
        if (size == -1)
        {
            Error = true;
        }
        int temp = child[size];
        size--;
        return temp;
    };
};

int main()
{
    Stack *stack = new Stack();
    string str;
    cin >> str;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
        {
            stack->push(1);
        }
        if (str[i] == ')')
        {
            stack->pop();
        }
    }
    if (stack->size == -1 && !stack->Error)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
}