#include <map>
using namespace std;
struct Edge {
    const string* str; // hangi string’e ait
    int start;              // substring başlangıcı
    int len;                // substring uzunluğu
    Node* to;               // hedef node
    Edge(){
        str=nullptr;
        start=0;
        len=0;
        to=nullptr;
    }
    Edge(const string* str,int start,int len,Node* to):str(str),start(start),len(len),to(to){}
};
struct Node{
    int value;
    map<char,Edge> outgoing_edges;
    Node(){
        value=-1;
    }
    Node(int v){
        value=v;
    }
};
class compressedTrie{
    public:
        compressedTrie(){
            root= new Node();
        }
        void insert(const string& key){
            
        }
    private:
        Node* root;



};
