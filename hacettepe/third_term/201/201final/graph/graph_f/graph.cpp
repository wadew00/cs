#include <string>
#include <set>
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node{
    int id;
    string heavyData;
    bool operator<(const Node& other) const {
        return id<other.id;
    }
    bool operator==(const Node& other) const {
        return id == other.id;
    }
};
class Graph{
    private:
        set<Node> Nodes;
        map<Node,list<Node>> adj;
        // alternative vector<Vertex*> vertices;
    public:
        void addNode(const Node& node){
            Nodes.insert(node);
            adj[node];
        }
        void addEdge(const Node& u,const Node& v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        list<Node> getAllNeighbours(const Node& n){
            return adj[n];
        }
        void dfsRecursive(Node& v,vector<bool>& visited){
            visited[v.id]= true;
            cout<<"Visited: "<<v.heavyData<<endl;
            for(auto& ver: adj[v]){
                if(visited[ver.id]==false){
                    dfsRecursive(ver,visited);
                }
            }
        }
        void dfsIter(Node& v){
            vector<bool> visited(8,false);
            stack<Node> s;
            s.push(v);
            visited[v.id]=true;
            cout<<"Visited: "<<v.heavyData<<endl;
            while(!s.empty()){
                Node x = s.top();
                s.pop();
                for(auto& v: adj[x]){
                    if(visited[v.id]==false){
                        cout<<"Visited: "<<v.heavyData<<endl;
                        visited[v.id]=true;
                        s.push(v);
                    }
                }
            }
        }
};
int main(){
    Graph g;

    // CREATE NODES TO TEST
    Node n1 = {0, "data_v"};
    Node n2 = {1, "Data_u"};
    Node n3 = {2, "Data_w"};
    Node n4 = {3, "data_x"};
    Node n5 = {4, "Data_q"};
    Node n6 = {5, "Data_t"};
    Node n7 = {6, "Data_r"};
    Node n8 = {7, "Data_s"};
    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);
    g.addNode(n4);
    g.addNode(n5);
    g.addNode(n6);
    g.addNode(n7);
    g.addNode(n8);

    // CONSTRUCT THEIR EDGES
    g.addEdge(n1,n2);
    g.addEdge(n1,n3);
    g.addEdge(n1,n4);
    g.addEdge(n2,n5);
    g.addEdge(n2,n6);
    g.addEdge(n5,n7);
    g.addEdge(n5,n8);

    //  Retrieve and Print Neighbors
    cout << "Neighbors of Node " << n2.id << " (" << n2.heavyData << "):\n";
    list<Node> neighbors = g.getAllNeighbours(n2);
    for(const auto& neighbor : neighbors){
        cout << " - ID: " << neighbor.id << ", Data: " << neighbor.heavyData << endl;
    }
    // DFS RECURSIVE TEST
    vector<bool> visited(8,false);
    cout<<"DFS RECURSIVE TEST"<<endl;
    g.dfsRecursive(n1,visited);
    cout<< "DFS RECURSIVE TEST END"<<endl;
    // DFS ITER TEST
    cout<<"DFS ITERATIVE TEST"<<endl;
    g.dfsIter(n1);
    cout<< "DFS ITERATIVE TEST END"<<endl;
    return 0;
}