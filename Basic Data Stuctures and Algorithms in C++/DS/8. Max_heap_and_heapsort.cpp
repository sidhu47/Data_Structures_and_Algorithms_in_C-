#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Heap{
    private:
    vector<int> h = {0};
    
    public:
    void push(int k){
        h.push_back(k);
        int n = h.size() - 1;
        
        int i = n, temp = k;
        
        while(i > 1 && temp > h[i / 2]){
            swap(h[i], h[i / 2]);
            i = i / 2;
        }
        //print_heap();
    }
    
    int pop(){                  //frees memory too
        int val = h[1], n = h.size() - 1;
        swap(h[1], h[n]);        
        int i = 1, j = 2 * i, temp = h[1];
        
        while(j < n - 1){
            if(h[j + 1] > h[j])j++;
            
            if(h[i] < h[j]){
                swap(h[i], h[j]);
                i = j;
                j = 2 * i;
            }
            else break;
        }
        
        h.pop_back();
        //print_heap();
        return val;
    }
    
    void pop_for_heapsort(int index){   //does not free memory of popped elements
        swap(h[1], h[index]);
        
        int i = 1, j = 2 * i;
        
        while(j < index - 1){
            if(h[j + 1] > h[j])j++;
            
            if(h[i] < h[j]){
                swap(h[i], h[j]);
                i = j;
                j = 2 * i;
            }
            else break;
        }
    }
    
    void heapsort(){
        vector<int> temp = h;
        int n = h.size() - 1;
        
        for(int index = n; index >= 1; index--)pop_for_heapsort(index);
        
        print_heap();
        h = temp;
        //print_heap();
    }
    
    void print_heap(){
        for(int i = 1; i < h.size(); i++)cout << h[i] << " ";
        cout << endl;
    }
};

int main() {
	// your code goes here
	Heap h;
	h.push(10);
	h.push(20);
	h.push(30);
	h.push(25);
	h.push(5);
	h.push(40);
	h.push(35);
	
	h.print_heap();
	
	h.heapsort();
	
	for(int i = 0; i < 7; i++)cout << h.pop() << endl;
	
	return 0;
}
