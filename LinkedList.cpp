#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    };
};

class LinkedList
{
public:
    Node *head = NULL;
    LinkedList(){};
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node *getLastPtr()
    {
        Node *lastPtr = head;
        Node *prev;
        while (lastPtr != NULL)
        {
            prev = lastPtr;
            lastPtr = lastPtr->next;
        }
        return prev;
    }
    void pushFront(int data)
    {
        Node *node;
        node = new Node(data, head);
        this->head = node;
    };

    void add(int data)
    {
        Node *lastPtr = getLastPtr();
        Node *node = new Node(data, NULL);
        lastPtr->next = node;
    }

    void popFront()
    {
        Node *prevHead = head;
        head = head->next;
        delete (prevHead);
    };

    int search(int data)
    {
        int index = 0;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                return index;
            }
            ptr = ptr->next;
            index++;
        }

        return -1;
    }
    Node *getPtrIdx(int index)
    {
        Node *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
    void insertBefore(int data, int target)
    {
        if (isEmpty())
        {
            pushFront(data);
        }
        else
        {

            int foundIndex = search(target);
            if (foundIndex != -1)
            {
                Node *ptr = getPtrIdx(foundIndex);
                if (ptr == head)
                {
                    pushFront(data);
                }
                else
                {
                    Node *prevPtr = getPtrIdx(foundIndex - 1);
                    Node *newNode = new Node(data, ptr);
                    prevPtr->next = newNode;
                }
            }
            else
            {
                this->add(data);
            };
        }
    };
    void addAfter(int data, int target)
    {
        if (isEmpty())
        {
            pushFront(data);
        }
        else
        {

            int foundIndex = search(target);
            if (foundIndex != -1)
            {
                Node *ptr = getPtrIdx(foundIndex);
                Node *newPtr = new Node(data, ptr->next);
                ptr->next = newPtr;
            }
            else
            {
                this->add(data);
            }
        }
    }
    void delId(int data)
    {
        int foundIndex = search(data);
        if (foundIndex != -1)
        {
            if (getLastPtr() != head)
            {
                Node *ptr = getPtrIdx(foundIndex);
                if (ptr == head)
                {
                    popFront();
                    print();
                }
                else
                {
                    Node *prevPtr = getPtrIdx(foundIndex - 1);
                    Node *nextPtr = getPtrIdx(foundIndex + 1);
                    delete (ptr);
                    prevPtr->next = nextPtr;
                    print();
                }
            }
        }
    }
    void print()
    {
        Node *pointing_at = head;

        while (pointing_at != NULL)
        {

            cout << pointing_at->data << " ";
            pointing_at = pointing_at->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList *linkedList = new LinkedList();
    char operation;
    do
    {
        cin >> operation;
        switch (operation)
        {
        case 'A':
            int dataA, idA;
            cin >> dataA;
            cin >> idA;
            if (linkedList->search(dataA) == -1)
            {
                linkedList->addAfter(dataA, idA);
                linkedList->print();
            }

            break;
        case 'I':
            int data, id;
            cin >> data;
            cin >> id;
            if (linkedList->search(data) == -1)
            {
                linkedList->insertBefore(data, id);
                linkedList->print();
            }
            break;
        case 'D':
            int IdD;
            cin >> IdD;
            linkedList->delId(IdD);
            break;
        }
    } while (operation != 'E');

    return 0;
}
