#include<bits/stdc++.h>
using namespace std;
struct AVLTree{
	struct node{
		int data;
		node* left;
		node* right;
		int height;
	};
	node* head = nullptr;
	int getHeight(node* node){
		if(node == nullptr)
			return 0;
		return node->height;
	}
	int newHeight(node* node){
		return (max(getHeight(node->left), getHeight(node->right)) + 1);
	}
	node* getNewNode(int data){
		node* newNode = new node;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = data;
		newNode->height = 1;
		return newNode;
	}
	node* getMinNode(node* root){
		node* temp = root;
		while(temp->left != nullptr)
			temp = temp->left;
		return temp;
	}
	void RR(node* &x){
		node* temp = x->left;
		node* child = temp->right;
		temp->right = x;
		x->left = child;
		x->height = newHeight(x);
		temp->height = newHeight(temp);
		x = temp;
	}
	void LL(node* &x){
		node* temp = x->right;
		node* child = temp->left;
		temp->left = x;
		x->right = child;
		x->height = newHeight(x);
		temp->height = newHeight(temp);
		x = temp;
	}
	void LR(node* &x){
		LL(x->left);
		RR(x);
	}
	void RL(node* &x){
		RR(x->right);
		LL(x);
	}
	void organiseTree(node* &root, int key){
		if(root == nullptr)
			return;
		root->height = newHeight(root);
		int balance = getHeight(root->left) - getHeight(root->right);
		if(balance > 1){
			if(key < root->left->data){
				RR(root);
				return;
			}
			LR(root);
			return;
		}
		if(balance < -1){
			if(key > root->right->data){
				LL(root);
				return;
			}
			RL(root);
			return;
		}
	}
	void insert(node* &root, int key){
		if(root == nullptr){
			root = getNewNode(key);
			return;
		}
		if(root->data > key)
			insert(root->left, key);
		else
			insert(root->right, key);

		organiseTree(root, key);
	}
	void remove(node* &root, int key){
		if(root == nullptr)
			return;
		if(root->data > key)
			remove(root->left, key);
		else if(root->data < key)
			remove(root->right, key);
		else{
			if(root->left == nullptr || root->right == nullptr){
				node* child;
				if(root->left != nullptr)
					child = root->left;
				else
					child = root->right;
				if(child == nullptr){
					child = root;
					root = nullptr;
				} else {
					*root = *child;
				}
				delete child;
			} else {
				node* smol = getMinNode(root->right);
				root->data = smol->data;
				remove(root->right, smol->data); 
			}
		}
		organiseTree(root, key);
	}
	void print(node* temp){
		if(temp != nullptr){
			print(temp->left);
			cout << temp->data << " ";
			print(temp->right);
		}
	}
	void traverse(node* node, int height, int level, int maxHeight) {
    if (node == nullptr || getHeight(node) < height)
        return;
    if (getHeight(node) == height){
    	int cnst = maxHeight - level;
        int spaces = (1 << (cnst)) - 1; 
        int val = 1;
        while(cnst--)
        	val *= 2;
        for (int i = 0; i < spaces+val; i++)
            cout << " ";
        if (node->data > 9)
            cout << node->data;
        else
            cout << node->data << " ";
        for (int i = 0; i < spaces + val; i++)
            cout << " ";
        return;
    }
    traverse(node->left, height, level + 1, maxHeight);
    traverse(node->right, height, level + 1, maxHeight);
}
void showTree() {
    int maxHeight = getHeight(head);
    for (int height = maxHeight; height > 0; height--){
        traverse(head, height, 1, maxHeight);
        cout << endl << endl; 
    }
}

};
int main(){
	AVLTree tree;
    tree.insert(tree.head, 1);
    tree.insert(tree.head, 5);
    tree.insert(tree.head, 7);
    tree.insert(tree.head, 2);
    tree.insert(tree.head, 0);
    tree.insert(tree.head, 6);
    tree.insert(tree.head, 9);
    tree.insert(tree.head, 11);
    tree.insert(tree.head, 22);
    tree.insert(tree.head, 12);
    tree.insert(tree.head, 13);
    tree.insert(tree.head, 14);
    tree.insert(tree.head, 15);
    tree.insert(tree.head, 45);
    tree.insert(tree.head, 16);
    tree.print(tree.head);
    cout << endl << endl;
    tree.showTree();
}
