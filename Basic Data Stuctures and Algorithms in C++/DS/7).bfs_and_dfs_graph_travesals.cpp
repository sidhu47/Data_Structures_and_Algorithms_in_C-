#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
        for(int i = 0;i < g.size(); i++){
            cout << i+1 << " ==> ";
            for(int j = 0; j < g[i].size();j++){
                cout << g[i][j] << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    void bfs(int n){
        queue<int> q;
        vector<bool> visit(v,false);
        q.push(n);
        cout << q.front() << " ==> ";
        while(!q.empty()){
            int curr = q.front();
            if(visit[curr-1] == false)visit[curr-1] = true;
            q.pop();
            for(int i = 0; i < g[curr-1].size();i++){
                if(visit[g[curr-1][i]-1] == false){
                    cout << g[curr-1][i] << " -> ";
                    q.push(g[curr-1][i]); 
                    visit[g[curr-1][i]-1] = true;
                }
            }
        }
        cout << "END" << endl;
    }

    void dfs(int n){
        stack<int> s;
        vector<bool> visit(v,false);
        s.push(n);
        cout << n << " ==> ";
        while(!s.empty()){
            int curr = s.top();
            if(visit[curr-1] == true){
                s.pop();
            }
            else{
                visit[curr-1] = true;
                for(int i = 0; i < g[curr-1].size(); i++){
                    if(visit[g[curr-1][i]-1] == false){ //searches for first unvisited node and starts from that node
                        cout << g[curr-1][i] << " -> ";
                        s.push(g[curr-1][i]);
                        break;
                    }
                }
            }
        }
        cout << " END\n";
    }
};

int main(){
    int v;
    cout << "Enter the no of vertices: ";
    cin >> v;
    cout << "Enter the no of edges: ";
    int e;
    cin >> e;
    graph g = graph(5);
    int edgelist[e][2];
    for(int i = 0; i < e;i++){
        cout << "Enter the edges " << i+1 << " as s d: " << endl;
        cin >> edgelist[i][0] >> edgelist[i][1];
    }

    for(int i = 0; i < e;i++){
        g.addedge(edgelist[i][0],edgelist[i][1]);
    }
    g.display();
    cout << endl;
    g.bfs(5);
    g.dfs(1);
    return 0;
}
