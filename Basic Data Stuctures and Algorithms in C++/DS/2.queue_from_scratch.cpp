#include <iostream>

using namespace std;
#define N 5

class queue{
    public:
    int q[N];
    int head;
    int tail;
    
    public:
    queue(){
        head = -1;
        tail = -1;
    }

    void isfull(){
        if((tail + 1) % N == head){
            cout << "queue is full" << endl;
        }
        else cout << "Not full" << endl;
    }

    void isempty(){
        if(head == -1 && tail == -1){
            cout << "queue is empty" << endl;
        }
        else cout << "Not empty" << endl;
    }

    void enqueue(int n){
        if((tail + 1) % N == head){
            cout << "Queue is full" << endl;
        }
        else{
            cout << n << " is enqueued" << endl;
            if(head == -1 && tail == -1){
                q[++tail] = n;
                head++;
                //cout << head << endl;
            }else{
                tail = (tail + 1) % N;
                q[tail] = n;   
            }
        }
    }

    void dequeue(){
        if(head == -1 && tail == -1){
            cout << "Queue is empty"<< endl;
        }
        else{
            if(head == tail){
                cout << q[head] << " is dequeued" << endl;
                head = tail = -1;
            }
            else{
                cout << q[head] << " is dequeued" << endl;
                head = (head + 1) % N;
            }
        }
    }

    void front(){
        if(head == -1 && tail == -1)cout << "Queue is empty" << endl;
        else{
            cout << q[head] << " is the front element in the queue" << endl;
        }
    }

    void display(){
        if(head == -1){
            cout << "Queue is empty" << endl;
        }
        else{
            int i = head;
            while(true){
                if(i == tail){
                    cout << q[i] << endl;
                    break;
                }
            cout << q[i] << " ";
            i = (i + 1) % N;
            }
        }
    }
};

int main(){
    queue q = queue();
    q.isempty();
	q.isfull();
	q.display();
	q.enqueue(1);
	q.display();
	q.isempty();
	q.isfull();
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.display();
	q.enqueue(5);
	q.display();
	q.isfull();
	q.enqueue(6);
	q.dequeue();
    q.enqueue(6);
	q.display();
	q.dequeue();
	q.dequeue();
    q.display();
	q.front();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();

    return 0;
}