#include <iostream>
using namespace std;

struct AVLTree {
    struct node {
        int val;
        node* left;
        node* right;
        int height;
    };

    node* primaryRoot = nullptr;

    int getHeight(node* x) {
        if (x == nullptr)
            return 0;
        return x->height;
    }

    int getMax(int a, int b) {
        return (a > b) ? a : b;
    }

    node* createNewNode(int key) {
        node* newNode = new node;
        newNode->val = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    node * getMinNode(node* thisNode) 
    { 
        node* current = thisNode; 
        while (current->left != NULL){
            current = current->left; 
        }
        return current; 
    }

    void rotateRight(node* &x) {
        node* temp = x->left;
        node* temp2 = temp->right;

        temp->right = x;
        x->left = temp2;

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        temp->height = getMax(getHeight(temp->left), getHeight(temp->right)) + 1;

        x = temp;
    }

    void rotateLeft(node* &x) {
        node* temp = x->right;
        node* temp2 = temp->left;

        temp->left = x;
        x->right = temp2;

        x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
        temp->height = getMax(getHeight(temp->left), getHeight(temp->right)) + 1;

        x = temp;
    }

    //reorganise tree
    void organiseTree(node* &root, int key){
        root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getHeight(root->left) - getHeight(root->right);

        if (balance > 1 && key < root->left->val)
            rotateRight(root);
        else if (balance < -1 && key > root->right->val)
            rotateLeft(root);
        else if (balance > 1 && key > root->left->val) {
            rotateLeft(root->left);
            rotateRight(root);
        }
        else if (balance < -1 && key < root->right->val) {
            rotateRight(root->right);
            rotateLeft(root);
        }
    }


    //inserter function
    void insert(node* &root, int key) {
        if (root == nullptr) {
            root = createNewNode(key);
            return;
        }

        if (key < root->val)
            insert(root->left, key);
        else
            insert(root->right, key);

        organiseTree(root, key);
    }

    //deletion function
    void remove(node* &root, int key){
        if(root == NULL)
            return;

        if(key > root->val)
            remove(root->right, key);
        if(key < root->val)
            remove(root->left, key);

        if(key == root->val){

            if( (root->left == NULL) || (root->right == NULL) ) 
            { 
                node* temp = root->left ? root->left : root->right; 
                if (temp == NULL) 
                { 
                    temp = root; 
                    root = NULL; 
                } 
                else  
                    *root = *temp; 

                free(temp); 
            } 
            else
            {  
                node* temp = getMinNode(root->right); 
                root->val = temp->val;  
                remove(root->right, temp->val); 
            } 
        }

        if(root == NULL)
            return;

        organiseTree(root, key);
    }


    //print function
    void print(node* root) {
        if (root != nullptr) {
            print(root->left);
            cout << root->val << " ";
            print(root->right);
        }
    }
};

int main() {
    AVLTree tree;
    tree.insert(tree.primaryRoot, 1);
    tree.insert(tree.primaryRoot, 5);
    tree.insert(tree.primaryRoot, 2);
    tree.insert(tree.primaryRoot, 6);
    tree.insert(tree.primaryRoot, 3);
    tree.insert(tree.primaryRoot, 4);
    tree.print(tree.primaryRoot);
    cout << endl;
    tree.remove(tree.primaryRoot, 2);
    tree.print(tree.primaryRoot);

    return 0;
}
