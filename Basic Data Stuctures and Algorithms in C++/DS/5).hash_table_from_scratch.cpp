#include <iostream>
#include <vector>

using namespace std;

class hashish{
    public:
    int size;
    vector<vector<int>> htable;

    public:
    hashish(int n){
        size = n;
        htable.resize(size);
    }

    int hashcodegenerator(int n){
        int key;
	    key = n%10;
	    return key;
    }

    void insert(int n){
        int code = hashcodegenerator(n);
        htable[code].push_back(n);
    }

    void deletenode(int n){
        int code = hashcodegenerator(n);
        for(auto it = htable[code].begin(); it < htable[code].end() ;it++){
            if(*it == n){
                htable[code].erase(it);
            }
        }
    }

    void search(int n){
        int code = hashcodegenerator(n);
        int i;
        for( i = 0; i < htable[code].size() ;i++){
            if(htable[code][i] == n){
                cout << n << " is present in hash table in row " << code+1 << " & position no " << i+1 << endl;
                break;
            }
        }
        if(i >= htable[code].size())cout << n << " is not there in the hash table\n";
    }

    void display(){
        for(int i = 0; i < htable.size() ; i++){
            cout << i+1 << " ==> ";
            for(int j = 0; j < htable[i].size(); j++){
                cout << htable[i][j] << " -> " ;
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    hashish h = hashish(10);
    h.insert(1);
	h.insert(24);
	h.insert(22);
	h.insert(38);
	h.insert(88);
	h.insert(100);
	h.insert(20);
	h.insert(42);
	h.insert(32);
	h.insert(44);
	h.insert(36);
	h.insert(37);
	h.insert(47);
	h.insert(86);
	h.insert(55);
	h.insert(89);
	h.insert(99);
	h.insert(25);
	h.insert(22);
	h.insert(32);
    h.display();
    h.search(42);
    cout << endl << endl;
    h.deletenode(22);
    h.display();
    return 0;
}