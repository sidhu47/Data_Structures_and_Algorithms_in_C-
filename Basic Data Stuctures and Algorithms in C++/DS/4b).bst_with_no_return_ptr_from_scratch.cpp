#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    public:
    node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

class bst{
    public:
    node *root;

    public:
    bst(){
        root = NULL;
    }

    void insert(node **root,int n){
        node *temp = new node(n);
        if(*root == NULL){
            *root = temp;
        }
        else if(n < (*root)->data)insert(&((*root)->left),n);
        else insert(&((*root)->right),n);
    }

    void deletenode(node **root, int n){
        if(*root == NULL) return;
        if(n < (*root)->data) deletenode(&((*root)->left),n);
        else if(n > (*root)->data) deletenode(&((*root)->right),n);
        else{
            if((*root)->left == NULL && (*root)->right == NULL){
                delete *root;
                *root = NULL;
            }
            else if((*root)->left == NULL){
                node *temp = *root;
                *root = (*root)->right;
                delete temp;
            }
            else if((*root)->right == NULL){
                node *temp = *root;
                *root = (*root)->left;
                delete temp;
            }
            else{
                node *temp = findmin((*root)->right);
                (*root)->data = temp->data;
                deletenode(&((*root)->right), temp->data);
            }
        }
    }

    node *findmin(node *root){
        while(root->left != NULL){
            root = (root)->left;
        }
        return root;
    }

    void inorder(node **root){
        if(*root == NULL) return;
        inorder(&((*root)->left));
        cout << (*root)->data << " ";
        inorder(&((*root)->right));
    }

};

int main(){
    bst b = bst();
    b.insert(&(b.root),10);	
	b.insert(&(b.root),5);
	b.insert(&(b.root),20);
	b.insert(&(b.root),1);
	b.insert(&(b.root),8);
	b.insert(&(b.root),15);
	b.insert(&(b.root),25);
	b.insert(&(b.root),6);
    b.insert(&(b.root),17);
    b.insert(&(b.root),23);
    b.insert(&(b.root),26);

    b.inorder(&(b.root));
    cout << endl;

    cout << "root is " << b.root->data << endl;

    b.deletenode(&(b.root),10);
    b.inorder(&(b.root));
    cout << endl;

    cout << "root is " << b.root->data << endl;

    b.deletenode(&(b.root),17);
    b.inorder(&(b.root));
    cout << endl;

    b.deletenode(&(b.root),8);
    b.inorder(&(b.root));
    cout << endl;

    b.deletenode(&(b.root),20);
    b.inorder(&(b.root));
    cout << endl;

    b.deletenode(&(b.root),1);
    b.inorder(&(b.root));
    cout << endl;

    b.deletenode(&(b.root),23);
    b.inorder(&(b.root));
    cout << endl;

    cout << "root is " << b.root->data << endl;

    return 0;
}