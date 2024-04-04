#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int arr[100];
    Stack()
    {
        this->top = -1;
    }
    void push(int num)
    {
        size++;
        top++;
        arr[top] = num;
    }
    int pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getLast()
    {
        return arr[top];
    }
};

int main()
{
    Stack *stack;
    stack = new Stack();
    char operation = 'c';
    int num;
    do
    {
        cin >> operation;
        switch (operation)
        {
        case 'u':
            cin >> num;
            stack->push(num);
            break;
        case 'o':;
            cout << stack->pop() << endl;
            break;
        case 't':
            cout << stack->getLast() << endl;
            break;
        case 'p':
            stack->print();
            break;
        case 'n':
            cout << stack->size << endl;
            break;
        }
    } while (operation != 'x');

    return 0;
}