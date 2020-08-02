#include <bits/stdc++.h>
#define INF 21453489

using namespace std;

class graph{
    public:
    int v;
    int e;
    int **edgelist; 
    int **gc;

    public:
    graph(int n, int edges){
        v = n;
        e = edges;
        gc = new int*[v];
        edgelist = new int*[e];
        for(int i = 0; i < v; i++){
            gc[i] = new int[v];
        }

        for(int i = 0; i < e; i++){
            edgelist[i] = new int[3];
        }

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(i == j) gc[i][j] = 0;
                else gc[i][j] = INF;
            }
        }
    }

    void addedge(int s, int d, int c){
        gc[s-1][d-1] = c;
    }

    void display(){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << gc[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void bellmanford(int sv){
        int dist[v];
        for(int i = 0; i < v; i++)dist[i] = INF;
        dist[sv - 1] = 0;

        //for(int i = 0; i < v;i++)cout << dist[i] << " ";

        for(int i = 0 ; i < v - 1; i++){    //for v-1 times
            for(int j = 0; j < e; j++){     //relaxing all edges 
                int u = edgelist[j][0] - 1;
                int v = edgelist[j][1] - 1;
                int cost_from_u_to_v = edgelist[j][2];
                if(dist[v] > dist[u] + cost_from_u_to_v){
                    dist[v] = dist[u] + cost_from_u_to_v; //updating distance matrix
                }
            }
        }

        cout << "Final Distance Matrix from source vertex " << sv << " is: \n" << endl;
        for(int i = 0; i < v; i++){
            cout << sv << " to " << i+1 << " --> " << dist[i] << endl;
        }
        cout << endl;
    }
};

int main(){
    int v,e,s,d,c; //vertices, edges , source, destination, cost
    cout << "Enter the number of vertices and edges as v e: ";
    cin >> v >> e;

    graph g = graph(v,e);
    cout << "Enter the edges as s d c: \n";
    for(int i = 0; i < e; i++){
        cin >> s >> d >> c;
        g.edgelist[i][0] = s;
        g.edgelist[i][1] = d;
        g.edgelist[i][2] = c;
        g.addedge(s,d,c);
    }
    cout << endl;
    g.bellmanford(1);

}

/*
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
*/