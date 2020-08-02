#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
};

class linkedlist{
    public:
    node *head;
    public:
    linkedlist(){
        head = NULL;
    }
    //adding at the head O(1)
    void append(int n){
        cout << n << " is appended " << endl;
        node *temp = new node();
        temp->data = n;
        temp->next = NULL;
        if(head != NULL){
            temp->next = head;
        }
        head = temp;
    }
    //deleting at the head O(1)
    void remove(){
        cout << "removing\n";
        node *temp = head;
        if(head == NULL){
            cout << "List is empty" << endl;
        }
        else{
            //cout << "address of temp->next is " << temp->next << endl;
            //cout << "tadd = " << temp << " head = " << head << endl;
            cout << "head data " << head->data << " is being removed " << endl;
            head = head->next;
            //cout << "tadd = " << temp << " head = " << head << endl;
            delete temp;
            if(head == NULL){
                cout << "new head is NULL" << endl;
            }
            else cout << "new head is " << head->data << endl;
            //cout << "tadd = " << temp << " head = " << head << endl;
        }
    }

    void display(){
        if(head == NULL){
            cout << "list is empty" << endl;
        }else{
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    //Inserting at nth position worst case O(n)
    void addatn(int n, int i){ 
        cout << "addatn\n";
        node *temp = new node();
        temp->data = n;
        node* current = head;
        if(current->data == i){
            temp->next = head;
            head = temp;
        }
        while(current->next->data != i && current->next->next != NULL){
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    //deleting node n worst case O(n)
    void deletex(int n){
        cout << "deletex\n";
        node *temp = head;
        if(head == NULL) cout << "No elements in the list to delete" << endl;
        else{
            if(head->data == n){
                head = temp->next;
                delete temp;
            }
            else{
                while(temp->next->data != n){
                    temp = temp->next;
                }
                node *delnode;
                delnode = temp->next;
                temp->next = temp->next->next;
                delete delnode;
            }
        }
    }
};


int main(){
    linkedlist ll = linkedlist();
    ll.display();
    ll.remove();
    ll.append(4);
    ll.display();
    ll.remove();
    ll.deletex(4);
    ll.append(4);
    ll.display();
    ll.deletex(4);
    ll.display();
    ll.append(4);
    ll.append(3);
    
    ll.append(2);
    ll.append(1);
    
    ll.display();
    ll.remove();
    ll.display();
    
    ll.append(1);
    ll.display();
    
    ll.addatn(5,3);
    ll.display();
    ll.deletex(3);
    ll.display();

    return 0;
}