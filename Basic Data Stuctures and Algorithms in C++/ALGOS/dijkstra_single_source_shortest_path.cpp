#include <bits/stdc++.h>
#define INF 2147483 

using namespace std;

class graph{
    public:
    int v;
    int** gc;

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
                gc[i][j] = INF;
            }
        }
    }

    void addedge(int s, int d, int c){
        gc[s-1][d-1] = c;
        gc[d-1][s-1] = c;
    }
    
    void display(){
        for(int i = 0; i < v; i++){
            for(int j = 0 ; j < v; j++){
                cout << gc[i][j] << " ";
            }
            cout << endl;
        }
    }

    int findmin(int c[] , bool visit[]){
        int temp = INF;
        int t = 0;
        for(int i = 0; i < v; i++){
            if(c[i] < temp && !visit[i]){
                temp = c[i];
                t = i;
            } 
        }
        return t;
    }

    void dijkstra(int sv){
        int parent[v] = {0, 0 , 0 , 0 , 0};         //Used to track path using stack
        int dist[v] = {INF, INF, INF, INF, INF};    //Used to store distances from source to all nodes
        bool visit[v] = {false};                    //Used to store visted nodes globally
        dist[sv-1] = 0;
        
        for(int i = 0;i < v; i++){           //For all vertices
            int mini = findmin(dist, visit); //Check min distance in unvisited nodes
            visit[mini] = true;              //Mark it as visited
            for(int j = 0; j < v; j++){      //Check all its neighbours
                if(dist[j] > min(dist[j], dist[mini] + gc[mini][j])){   
                    dist[j] = min(dist[j], dist[mini] + gc[mini][j]);   //Relaxing the neighbours
                    parent[j] = mini;        //Update the parent of the relaxed neighbour
                }       
            }
        }

        cout << "Distance from source (" << sv << ") to all vertices are\n";

        for(int i = 0; i < v; i++){
            cout << "Distance is " << dist[i] << " -- " << sv << " to " << i+1 << endl;
        }
        cout << endl;

        int i = 0;
       
        cout << "Enter the vertex for path from source: " ;
        cin >> i;
        
        cout << "Path is ";
        stack<int> s;
        s.push(i);      //Push the elements in the path 
        while(parent[i-1] != sv - 1){
            s.push(parent[i-1] + 1);
            i = parent[i-1] + 1;
        }
        s.push(sv);

        while(!s.empty()){
            int top = s.top();
            cout << top << " -> ";
            s.pop();
        }
        cout << "NULL\n";
    }
};

int main(){
    int v,e,s,d,c; //vertices, edges , source, destination, cost
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    
    graph g = graph(v);
    //g.display();

    cout << "Enter the edges in the format of source dest cost: \n";

    for(int i = 0; i < e; i++){
        cin >> s >> d >> c;
        g.addedge(s,d,c);
    }

    //g.display();

    g.dijkstra(1);

    return 0;
}

/*
1 2 1
2 3 2
4 5 1
1 5 2
3 4 1
1 3 3

1 5 2
1 2 5
5 4 2
5 2 1
2 4 3
4 3 4
2 3 6
*/