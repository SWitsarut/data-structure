#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    string val;
    Node *next;
    Node(int key, string val, Node *next)
    {
        this->key = key;
        this->val = val;
        this->next = next;
    }
};

class HashTable
{
public:
    int n = 17;
    Node *heads[17];
    int R = 11;
    HashTable()
    {
        for (size_t i = 0; i < n; i++)
        {
            heads[i] = new Node(-1, "-", nullptr);
        }
    }
    void add(int key, string val)
    {
        int index = key % n;
        if (heads[index]->key != -1)
        {
            int fx = R - (key % R); // 11 - (17%11)
            for (size_t i = 0; i < n; i++)
            {
                int hi = (key + i * fx) % n;
                if (heads[hi]->key == -1)
                {
                    heads[hi] = new Node(key, val, nullptr);
                    break;
                }
            }
        }
        else
        {
            heads[index] = new Node(key, val, nullptr);
        }
    }
    void print()
    {
        for (size_t i = 0; i < n; i++)
        {
            Node *at = heads[i];
            while (at != nullptr)
            {
                cout << "(" << at->key << "," << at->val << ") ";
                at = at->next;
            }
            cout << endl;
        }
    }
    string search(int key)
    {
        int index = key % n;
        if (heads[index]->key != key)
        {
            int hx = key % R;
            int fx = R - (key % R);
            for (size_t i = 0; i < n; i++)
            {
                int hi = (key + i * fx) % n;
                if (heads[hi]->key == key)
                {
                    return heads[hi]->val;
                }
            }
            return "-";
        }
        return "-";
    }
};

int main()
{
    HashTable *ht = new HashTable();
    // ht->print();
    char operation = 'c';
    string val;
    do
    {
        cin >> operation;
        switch (operation)
        {
        case 'a':
            int key;
            cin >> key;
            cin >> val;
            ht->add(key, val);
            break;
        case 'p':
            ht->print();
            break;
        case 's':
            int Skey;
            cin >> Skey;
            cout << ht->search(Skey) << endl;
            break;
        default:
            break;
        }
    } while (operation != 'e');
    delete (ht);
    return 0;
}