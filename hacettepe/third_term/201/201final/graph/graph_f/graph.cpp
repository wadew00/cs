#include <string>
#include <set>
#include <map>
#include <list>
#include <iostream>
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
};
int main(){
    Graph g;
    Node n1 = {1, "Data_A"};
    Node n2 = {2, "Data_B"};
    Node n3 = {3, "Data_C"};

    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);

    g.addEdge(n1, n2);
    g.addEdge(n2, n3);

    // 5. Retrieve and Print Neighbors
    cout << "Neighbors of Node " << n2.id << " (" << n2.heavyData << "):\n";
    
    // We get a copy of the list here
    list<Node> neighbors = g.getAllNeighbours(n2);

    for(const auto& neighbor : neighbors){
        cout << " - ID: " << neighbor.id << ", Data: " << neighbor.heavyData << endl;
    }
    return 0;
}