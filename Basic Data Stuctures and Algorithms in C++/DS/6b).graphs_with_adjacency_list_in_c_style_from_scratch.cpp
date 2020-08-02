#include <iostream>

using namespace std;

class graphnode{
    public:
    int val;
    graphnode* next;

    public:
    graphnode(int n){
        val = n;
        next = NULL;
    }
};

class graph{
    public:
    int v;
    graphnode** glist;

    public:
    graph(int n){
        v = n;
        glist = new graphnode*[v];
        for(int i = 0;i < v;i++){
            glist[i] = NULL;
        }
    }

    void addedge(int s,int d){
        graphnode* source = new graphnode(d); //source vertex will have address to destination and vice versa
        graphnode* dest = new graphnode(s);
        
        graphnode* curr = glist[s-1];
        if(curr == NULL){
            glist[s-1] = source;
        }else{
            source->next = curr;
            glist[s-1] = source;
        }

        curr = glist[d-1];
        if(curr == NULL)glist[d-1] = dest;
        else{
            dest->next = curr;
            glist[d-1] = dest;
        }
    }

    void display(){
        graphnode* temp;
        for(int i = 0; i < v; i++){
            cout << i+1 << " ==> ";
            temp = glist[i];
            while(temp != NULL){
                cout  << temp->val << " -> " ;
                temp = temp->next;
            }
            cout << " NULL\n";
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