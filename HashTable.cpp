#include <iostream>
using namespace std;
class HashTable
{
public:
    int size;
    int n = 17;
    int key[17];
    string val[17];
    int R = 11;
    HashTable()
    {
        this->size = 0;
        for (int i = 0; i < n; i++)
        {
            key[i] = -1;
            val[i] = "-";
        }
    };
    int add(int key, string val)
    {
        int index = key % n;
        if (this->key[index] != -1)
        {
            int fx = R - (key % R); // 11 - (17%11)
            for (size_t i = 0; i < n; i++)
            {
                int hi = (key + i * fx) % n;
                if (this->key[hi] == -1)
                {
                    this->key[hi] = key;
                    this->val[hi] = val;
                    return 0;
                }
            }
        }
        else
        {
            this->key[index] = key;
            this->val[index] = val;
            return 0;
        }

        return -1;
    }
    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << "(" << this->key[i] << "," << this->val[i] << ") " << endl;
        }
    }
    string search(int key)
    {
        int index = key % n;
        if (this->key[index] != key)
        {
            int hx = key % R;
            int fx = R - (key % R);
            for (size_t i = 0; i < n; i++)
            {
                int hi = (key + i * fx) % n;
                if (this->key[hi] == key)
                {
                    return this->val[hi];
                }
            }
            return "-";
        }
        else
        {
            return this->val[key];
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