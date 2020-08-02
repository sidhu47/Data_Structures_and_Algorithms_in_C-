#include <iostream>

using namespace std;
#define SIZE 10

class stack{
    public:
    int top;
    int arr[SIZE];

    public:
    stack(){
        top = -1;
    }
    bool isempty(){
        if(top == -1) return true;
        else return false;
    }
    int peek(){
        if(top > -1) return arr[top];
        else return -1;
    }
    void push(int n){
        if(top < SIZE - 1){
            cout << n << " is pushed" << endl;
            arr[++top] = n;
        }
        else cout << "Overflow" << endl;
    }
    void pop(){
        if(top == -1){
            cout << "Underflow" << endl;
        }else{
            cout << arr[top--] << " is popped out" << endl;
        }
    }
    void display(){
        int i = 0;
        if(top > -1){
            while(i <= top){
                cout << arr[i] << " ";
                i++;
            }
            cout << endl;
        }
    }
};

int main(){
    stack s =  stack();
    s.pop();
    cout << s.peek() << endl;
    cout << s.isempty() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(10);
    s.push(9);
    s.push(11);
    s.display();
    cout << s.peek() <<endl;
    s.pop();
    cout << s.peek() << endl;
    s.display();
    return 0;
}