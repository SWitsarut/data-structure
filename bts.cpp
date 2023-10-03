#include <iostream>
using namespace std;

class Node
{
public:
	Node *left;
	int data;
	Node *right;
	Node(int data)
	{
		left = NULL;
		this->data = data;
		right = NULL;
	}
};

class Bst
{
public:
	Node *root = NULL;
	int size = 0;
	int getChildCount(Node *target)
	{
		int count = 0;
		if (target->left != NULL)
		{
			count++;
		}
		if (target->right != NULL)
		{
			count++;
		}
		return count;
	}

	void insert(int data)
	{
		size++;
		Node *newNode = new Node(data);
		if (root == NULL)
		{
			root = newNode;
			return;
		}
		Node *cur = root;
		while (true)
		{
			if (data < cur->data)
			{
				if (cur->left == NULL)
				{
					cur->left = newNode;
					return;
				}
				else
				{
					cur = cur->left;
				}
			}
			else
			{
				if (cur->right == NULL)
				{
					cur->right = newNode;
					break;
				}
				else
				{
					cur = cur->right;
				}
			}
		}
	}

	void remove(int data)
	{
		bool found = false;
		Node *cur = root;
		Node *prev = NULL;
		bool noElement = false;
		while (!found && !noElement)
		{
			if (data < cur->data)
			{
				//				left
				if (cur->left == NULL)
				{
					noElement = true;
				}
				else
				{
					prev = cur;
					cur = cur->left;
				}
			}
			if (data > cur->data)
			{
				//				right
				if (cur->right == NULL)
				{
					noElement = true;
				}
				else
				{
					prev = cur;
					cur = cur->right;
				}
			}
			if (data == cur->data)
			{
				found = true;
			}
		}
		if (found)
		{
			size--;
		}
		if (cur == root)
		{
			int targetChild = getChildCount(cur);
			if (targetChild == 0)
			{
				root = NULL;
			}
			else if (targetChild == 1)
			{
				if (cur->left != NULL)
				{
					root = cur->left;
				}
				else
				{
					root = cur->right;
				}
			}
			else if (targetChild == 2)
			{
				Node *tarReplace = cur->right;
				Node *tarReplaceParent = cur;
				while (tarReplace->left != NULL)
				{
					tarReplaceParent = tarReplace;
					tarReplace = tarReplace->left;
				}
				cur->data = tarReplace->data;
				if (tarReplaceParent->right == tarReplace)
				{
					tarReplaceParent->right = NULL;
				}
				else
				{
					tarReplaceParent->left = NULL;
				}
				delete tarReplace;
			}
		}
		else
		{
			int targetChild = getChildCount(cur);
			if (targetChild == 0)
			{
				if (prev->left == cur)
				{
					prev->left = NULL;
				}
				if (prev->right == cur)
				{
					prev->right = NULL;
				}
				delete cur;
			}
			if (targetChild == 1)
			{
				if (prev->right == cur)
				{
					if (cur->left != NULL)
					{
						prev->right = cur->left;
					}
					else
					{
						prev->right = cur->right;
					}
				}
				else
				{
					if (cur->left != NULL)
					{
						prev->left = cur->left;
					}
					else
					{
						prev->left = cur->right;
					}
				}
			}
			if (targetChild == 2)
			{
				Node *tarReplace = cur->left;
				Node *tarReplaceParent = cur;
				while (tarReplace->right != NULL)
				{
					tarReplaceParent = tarReplace;
					tarReplace = tarReplace->right;
				}
				cur->data = tarReplace->data;
				if (tarReplaceParent->right == tarReplace)
				{
					tarReplaceParent->right = NULL;
				}
				else
				{
					tarReplaceParent->left = NULL;
				}
				delete tarReplace;
			}
		}
	}
	void inorder(Node *target)
	{
		if (target != NULL)
		{
			inorder(target->left);
			cout << target->data << ",";
			inorder(target->right);
		}
		else
		{
			return;
		}
	}
	void preorder(Node *target)
	{
		if (target != NULL)
		{
			cout << target->data << ",";
			preorder(target->left);
			preorder(target->right);
		}
		else
		{
			return;
		}
	}
	void postorder(Node *target)
	{
		if (target != NULL)
		{
			postorder(target->left);
			postorder(target->right);
			cout << target->data << ",";
		}
		else
		{
			return;
		}
	}

	void printLevel(Node *n, int level)
	{
		if (level == 0)
		{
			cout << n->data << ",";
		}
		else
		{
			if (n->left != NULL)
			{
				printLevel(n->left, level - 1);
			}
			if (n->right != NULL)
			{
				printLevel(n->right, level - 1);
			}
		}
	}

	int h = 0, t_h = -1;
	void h_height(Node *n)
	{
		if (n != NULL)
		{
			t_h++;
			h_height(n->left);
			h_height(n->right);
			if (t_h > h)
			{
				h = t_h;
			}
			t_h--;
		}
	}

	int height(int v)
	{
		Node *n = root;
		while (true)
		{
			if (n->data > v && n->left != NULL)
			{
				n = n->left;
			}
			else if (n->data < v && n->right != NULL)
			{
				n = n->right;
			}
			else if (n->data == v)
			{
				h = 0, t_h = -1;
				h_height(n);
				return h;
			}
			else
			{
				return -1;
			}
		}
	}

	void Breadth()
	{
		for (int i = 0; i <= height(root->data); i++)
		{
			printLevel(root, i);
			cout << "|";
		}
		cout << endl;
	}
};

int main()
{
	Bst *tree = new Bst;
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
		case 'i':
			tree->inorder(tree->root);
			cout << endl;
			break;
		case 'p':
			tree->preorder(tree->root);
			cout << endl;
			break;
		case 't':
			tree->postorder(tree->root);
			cout << endl;
			break;
		case 'b':
			tree->Breadth();
			break;
		}
	} while (op != 'x');
	return 0;
}
