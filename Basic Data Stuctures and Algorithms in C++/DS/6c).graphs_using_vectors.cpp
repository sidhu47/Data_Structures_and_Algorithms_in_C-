#include <iostream>
#include <vector>

using namespace std;

class graph{
    public:
    int v;
    vector<vector<int>> g;

    public:
    graph(int n){
        v = n;
        g.resize(v);
    }

    void addedge(int s, int d){
        g[s-1].push_back(d);
        g[d-1].push_back(s);
    }

    void display(){
        for(int i = 0; i < g.size() ; i++){
            cout << i+1 << " ==> ";
            for(int j = 0; j < g[i].size(); j++){
                cout << g[i][j] << " -> " ;
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    cout << "Enter the number of vertices: ";
    int v;
    cin >> v;
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    graph g = graph(v);
    int edgelist[e][2]; // contains the source and destinations between vertices and for cost add cost variable like (s,d,c)
    cout << "Enter the edges source and destinations as s d: " << endl;
    
    for(int i = 0 ; i < e; i++){
        for(int j = 0; j < 2; j++){
            cin >> edgelist[i][j];
        }
    }
    cout << endl;

    for(int i = 0; i < e; i++){
        g.addedge(edgelist[i][0],edgelist[i][1]);
    }

    g.display();
    return 0;
}