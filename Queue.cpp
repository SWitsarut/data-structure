#include <iostream>

class Queue
{
private:
    int head = 0;
    int tail = -1;
    int size = 0;
    int n = 0;

public:
    int *queue;
    Queue(int size)
    {
        this->size = size;
        queue = new int[size];
    }
    void enqueue(int element)
    {
        tail++;
        n++;
        queue[tail] = element;
    }
    int dequeue()
    {
        int out = *(queue + head);
        head++;
        n--;
        return out;
    }
    void print()
    {
        if (n != 0)
        {

            for (size_t i = 0; i < n; i++)
            {
                printf("%d ", *(queue + head + i));
            }
            std::cout << std::endl;
        }
    }
    int getN()
    {
        return n;
    }
    void s()
    {
        if (n != 0)
        {
            printf("%d %d\n", *(queue + head), *(queue + tail));
        }
    }
};

int main()
{
    Queue queue(50);
    char input;
    do
    {
        std::cin >> input;
        switch (input)
        {
        case 'e':
            int newmember;
            std::cin >> newmember;
            queue.enqueue(newmember);
            break;
        case 'd':
            std::cout << queue.dequeue() << std::endl;
            break;
        case 'p':
            queue.print();
            break;
        case 'n':
            std::cout << queue.getN() << std::endl;
            break;
        case 's':
            queue.s();
            break;
        }

    } while (input != 'x');

    return 0;
}