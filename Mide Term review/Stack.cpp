#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int maxSize;
    bool isFull()
    {
        if ((arr + top) == (arr + maxSize - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Stack(int size)
    {
        top = -1;
        maxSize = size;
        arr = (int *)malloc(size * sizeof(int));
    }
    void add(int num)
    {
        arr[++top] = num;
    }
    int pop()
    {
        return arr[top--];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    char operation = 'D';
    Stack *st = new Stack(1);
    do
    {
        cin >> operation;
        int num;
        switch (operation)
        {
        case 'a':
            if (!st->isFull())
            {
                cin >> num;
                st->add(num);
            }
            else
            {
                cout << "stack is full" << endl;
            }
            break;
        case 'p':
            if (!st->isEmpty())
            {
                cout << st->pop() << endl;
            }
            else
            {
                cout << "stack is empty";
            }
            break;
        }
    } while (operation != 'x');

    return 0;
}