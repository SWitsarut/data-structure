#include <iostream>
using namespace std;

class CirQ
{
public:
    int head = 0;
    int rear = -1;
    int arr[3];
    int max = 3;
    int addPosition(int num, int amount)
    {
        return (num + amount) % max;
    }
    int addPosition(int num)
    {
        return (num + 1) % max;
    }
    void enQueue(int num)
    {
        rear = addPosition(rear);
        arr[rear] = num;
    }
    int deQueue()
    {
        int temp = arr[head];
        head = addPosition(head);
        return temp;
    }
    int size()
    {
        int Size = 0;
        for (int i = head; true; i = addPosition(i))
        {
            Size++;
            if (i == rear)
            {
                break;
            }
        }
        return Size;
    }
};

int main()
{
    CirQ *Q = new CirQ();
    // Q->enQueue(10);
    // Q->enQueue(5);
    // Q->enQueue(2);
    // Q->deQueue();
    // Q->enQueue(2);
    // cout << Q->rear;
    cout << Q->size();
    return 0;
}