#include <string>
#include <set>
#include <map>
using namespace std;
struct Node{
    int data;
    string payload;
    bool operator<(const Node& node2){
    return (data<node2.data);
    }
};
class AdjacencyMatrix{
    set<Node> nodes;
    map<Node,map<Node,bool>> adjacencyMatrix;
    void addNode(const Node& node){
        nodes.insert(node);
        map<Node,bool> matrixRow;
        
    }
};

int main(){


    return 0;
}
