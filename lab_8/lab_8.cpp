#include <iostream>
#include <cstdlib>
using namespace std;

class TernaryTree {
private:
	int value;
	TernaryTree* left;
	TernaryTree* middle;
	TernaryTree* right;

public:
	TernaryTree(int value) {
		this->left = NULL;
		this->middle = NULL;
		this->right = NULL;
		this->value = value;
	}

	TernaryTree* AddElement(TernaryTree* root, int value) {
		if (root == NULL) {
			TernaryTree* root = new TernaryTree(value);
			return root;
		} else {
			if (value < root->value) {
				root->left = AddElement(root->left, value);
			}
			if (value == root->value) {
				root->middle = AddElement(root->middle, value);
			}
			if (value > root->value) {
				root->right = AddElement(root->right, value);
			}
			return root;
		}
	}

	void PrintTree(){
		if (this->left != NULL) {
			this->left->PrintTree();
		}
		if (this->middle != NULL) {
			this->middle->PrintTree();
		}
		cout << this->value << " ";
		if (this->right != NULL) {
			this->right->PrintTree();
		}
	}

	void FreeMemory(TernaryTree* root) {
		if (root != NULL) {
			FreeMemory(root->left);
			FreeMemory(root->middle);
			FreeMemory(root->right);
			delete root;
		}
	}
};

int main()
{
	TernaryTree* root = new TernaryTree(rand() % 10);
	for (int i = 0; i < 20; i++) {
		(*root).AddElement(root, rand() % 10);
	}
	root->PrintTree();
	root->FreeMemory(root);
	return 0;
}
