#include <iostream>
using namespace std;

struct binary_tree{
	struct node{
		int value;
		node* left;
		node* right;
	};
	node* p = NULL;

	void printInorder(node* p){
		if(!p)
			return;
		printInorder(p->left);
		cout << p->value << " ";
		printInorder(p->right);
	}

	void printPreorder(node* p){
		if(!p)
			return;
		cout << p->value << " ";
		printPreorder(p->left);
		printPreorder(p->right);
	}

	void printPostorder(node* p){
		if(!p)
			return;
		printPostorder(p->left);
		printPostorder(p->right);
		cout << p->value << " ";
	}

	bool binary_search(node* p, int x){
		if(!p)
			return false;
		if(p->value == x){
			return true;
		}
		if(x >= p->value)
			return binary_search(p->right, x);
		else
			return binary_search(p->left, x);
	}

	void inserter(node* p, node* new_node){
		if(p->value <= new_node->value && p->right == NULL){
			p->right = new_node;
			return;
		}
		else if (p->value >= new_node->value && p->left == NULL){
			p->left = new_node;
			return;
		}
		else if(p->value >= new_node->value){
			inserter(p->left, new_node);
		}
		else{
			inserter(p->right, new_node);
		}
	}

	void insert(int x){
		node* new_node = new node;
		new_node->value = x;
		new_node->left = NULL;
		new_node->right = NULL;
		if(!p)
			p = new_node;
		else{
			inserter(p, new_node);
		}
	}
};

int main(){
	binary_tree Tree;
	int n, q, x;
	cin >> n;
	while(n--)
	{
		cin >> x;
		Tree.insert(x);
	}
	cout << "\nInorder: " << endl;
	Tree.printInorder(Tree.p);
	cout << "\nPreorder: " << endl;
	Tree.printPreorder(Tree.p);
	cout << "\nPostorder: " << endl;
	Tree.printPostorder(Tree.p);
	cout << endl;

	cin >> q;
	while(q--)
	{
		cin >> x;
		cout << "Status: " << Tree.binary_search(Tree.p, x) << endl;
	}
	return 0;
}