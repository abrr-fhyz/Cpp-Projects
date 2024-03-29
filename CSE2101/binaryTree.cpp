#include <iostream>
using namespace std;

struct binary_tree{
	struct node{
		int value;
		node* left;
		node* right;
		node* parent;
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

	node* search(node* p, int x){
		if(!p)
			return NULL;
		if(p->value == x){
			return p;
		}
		if(x >= p->value)
			return search(p->right, x);
		else
			return search(p->left, x);
	}

	void inserter(node* p, node* new_node){
		if(p->value <= new_node->value && p->right == NULL){
			p->right = new_node;
			new_node->parent = p;
			return;
		}
		else if (p->value >= new_node->value && p->left == NULL){
			p->left = new_node;
			new_node->parent = p;
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
		new_node->parent = NULL;
		if(!p)
			p = new_node;
		else{
			inserter(p, new_node);
		}
	}

	node* findSmallest(node* p){
		p = p->right;
		if(!p)
			return NULL;
		while(p->left != NULL){
			p = p->left;
		}
		return p;
	}

	void deleteX(int x){
		node* nodeWithX = search(p, x);
		if(nodeWithX == NULL)
			return;
		//right side empty
		if(nodeWithX->right == NULL){
			node* parentX = nodeWithX->parent;
			if(!parentX){
				p = nodeWithX -> left;
				return;
			}
			if(parentX->left == nodeWithX){
				parentX->left = (nodeWithX->left);
				if(nodeWithX->left)
					(nodeWithX->left)->parent = parentX;
				return;
			}
			parentX->right = (nodeWithX->left);
			if(nodeWithX->right)
				(nodeWithX->left)->parent = parentX;
			return;
		}
		//rightside not empty
		node* parentX = nodeWithX->parent;
		node* smallestRight = findSmallest(nodeWithX);
		nodeWithX->value = smallestRight->value;
		if ((smallestRight->parent)->left == smallestRight)
            (smallestRight->parent)->left = smallestRight->right;
        else
            (smallestRight->parent)->right = smallestRight->right;

        if (smallestRight->right != NULL)
            (smallestRight->right)->parent = smallestRight->parent;
		return;
	}


};

void printEverything(binary_tree Tree){
	cout << "\nInorder: " << endl;
	Tree.printInorder(Tree.p);
	cout << "\nPreorder: " << endl;
	Tree.printPreorder(Tree.p);
	cout << "\nPostorder: " << endl;
	Tree.printPostorder(Tree.p);
	cout << endl;
}

int main(){
	binary_tree Tree;
	int n, q, x;
	cin >> n;
	while(n--)
	{
		cin >> x;
		Tree.insert(x);
	}
	printEverything(Tree);

	cin >> q;
	while(q--)
	{
		cin >> x;
		Tree.deleteX(x);
		printEverything(Tree);
	}
	return 0;
}
