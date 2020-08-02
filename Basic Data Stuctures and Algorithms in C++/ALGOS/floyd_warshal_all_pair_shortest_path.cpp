#include <bits/stdc++.h>

#define INF 21453489

using namespace std;

class graph{
    public:
    int v;
    int **gc;
    
    public:
    graph(int n){
        v = n;
        gc = new int*[v];
        for(int i = 0; i < v; i++){
            gc[i] = new int[v];
        }

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(i == j) gc[i][j] = 0;
                else
                gc[i][j] = INF;
            }
        }
    }

    void addedge(int s, int d, int c){
        gc[s - 1][d - 1] = c;
    }

    void display(){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << gc[i][j] << " ";
            }
            cout << endl;
        }
        cout  << endl;
    }

    void floydwarshal(){
        int c[v][v];
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                c[i][j] = gc[i][j];
            }
        }

        for(int k = 0; k < v; k++){
            for(int i = 0; i < v; i++){
                for(int j = 0; j < v; j++){
                    if(i != k && j != k){
                        c[i][j] = min(c[i][j],(c[i][k] + c[k][j]));
                    }
                }
            }
        }

        cout << "The final all pair shortest cost matrix is :\n";

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    int v,e,s,d,c;  //vertices, edges , source, destination, cost
    cout << "Enter the number of vertices and edges as v u: ";
    cin >> v >> e;
    graph g = graph(v);

    cout << "Enter the edges with their cost as s d c: \n";
    for(int i = 0; i < e; i++){
        cin >> s >> d >> c;
        g.addedge(s,d,c);
    }
    
    cout << endl;
    g.display();

    g.floydwarshal();

    return 0;
}

/*
1 2 3
1 4 7
2 1 8
2 3 2
3 1 5
3 4 1
4 1 2
*/