#include <iostream>

using namespace std;

int main(){
    cout << "Enter the number of vertices and edges as (v,e): ";
    int v,e;
    cin >> v >> e;
    
    // creating an adjacency matrix with all zeroes;
    //adjacency matrix will have size of (v*v)

    int adjamatrix[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0 ; j < v; j++){
           adjamatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < v; i++){
        for(int j = 0 ; j < v; j++){
            cout << adjamatrix[i][j] << " ";
        }
        cout << endl;
    }

    int edgelist[e][2]; // contains the source and destinations between vertices and for cost add cost variable like (s,d,c)
    cout << "Enter the edges source and destinations as s d: " << endl;
    for(int i = 0 ; i < e; i++){
        for(int j = 0; j < 2; j++){
            cin >> edgelist[i][j];
        }
    }

    for(int i = 0; i < e; i++){
        //you can create a cost adj matrix to add cost between nodes too;
        adjamatrix[edgelist[i][0]-1][edgelist[i][1]-1] = 1; //adj[x][y] = 1 => x = edjelist[i][0] - 1
        adjamatrix[edgelist[i][1]-1][edgelist[i][0]-1] = 1; //adj[y][x] = 1 => y = edjelist[i][1] - 1
    }

    cout << "The adjacency matrix is " << endl;

    for(int i = 0; i < v; i++){
        for(int j = 0 ; j < v; j++){
            cout << adjamatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
