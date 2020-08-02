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

    node *insert(node *root, int n){
        //cout << "insert" << endl;
        node *temp = new node(n);
        
        if(root == NULL){
            //cout << "root in NULL so in first loop" << endl;
            root = temp;
            //cout << "root -> data is " << root->data << endl;
        }
        else{
            //cout << "root is not NULL so in second loop\n";
            if(n < root->data){
                root->left = insert(root->left,n);
            }
            else{
                root->right = insert(root->right,n);
            }
        }
        return root;
    }

    node *deletenode(node *root, int n){
        if(root == NULL) return root;
        if(n < root->data)root->left = deletenode(root->left,n);
        else if(n > root->data)root->right = deletenode(root->right,n);
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            else if(root->left == NULL){
                node *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL){
                node *temp = root;
                root = root->left;
                delete temp;
            }
            else{
                node *temp = findmin(root->right);
                root->data = temp->data;
                root->right = deletenode(root->right,temp->data);
            }
        }
        return root;

    }

    node *findmin(node *root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    void inorder(node *root){
        //cout << "inorder\n";
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << "  " ;
        inorder(root->right);
    }
};

int main(){
    bst b = bst();
    b.root = b.insert(b.root, 10);
    b.root = b.insert(b.root, 5);
    b.root = b.insert(b.root, 20);
    b.root = b.insert(b.root, 1);
    b.root = b.insert(b.root, 8);
    b.root = b.insert(b.root, 15);
    b.root = b.insert(b.root, 25);
    b.root = b.insert(b.root, 6);
    b.root = b.insert(b.root, 17);
    b.root = b.insert(b.root, 23);
    b.root = b.insert(b.root, 26);
   

    b.inorder(b.root);
    cout << endl;
    //cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 10);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 17);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 8);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 20);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 1);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    b.root = b.deletenode(b.root, 23);
    b.inorder(b.root);
    cout << endl;
    cout << b.root->data << endl;

    return 0;
}