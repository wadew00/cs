#include <map>
#include <list>
#include <string>
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
        int commonPrefixLen(const string& key, int i, const Edge& edge) {
            int k = 0;
            while (true){
                if(i+k==key.size()){
                    break;
                }
                if(k==edge.len){
                    break;
                }
                if(key[i+k]!=(*edge.str)[edge.start+k]){
                    break;
                }
                k++;
            }
            return k;
        }
        void insert(const string& key,int value){
            pool.push_back(key);
            const string* kp= &pool.back();
            Node* n = root;
            int i= 0;
            while (true){
                // case 1 key fully consumed
                if(i==key.length()){
                    n->value=value;
                    return;
                }
                // case 2 no edge starting with key[i]
                char c = key[i];
                auto it = n->outgoing_edges.find(c);
                if(it==n->outgoing_edges.end()){
                    Node* newN= new Node(value);
                    n->outgoing_edges[c]=Edge(kp,i,key.length()-i,newN);
                    return;
                }
                // case 3 && 4 edge var
                Edge& edge= it->second;
                int k = commonPrefixLen(key, i, edge);
                // case 3 edge tamamen aynı
                if(k==edge.len){
                    i+=k;
                    n=edge.to;
                    continue;
                }
                // case 4 split (NOW)
                Node* mid = new Node();
                Node* oldChild= edge.to;

                // parent -> mid (common prefix)
                it->second=Edge(edge.str,edge.start,k,mid);

                // mid -> old suffix
                int old_suffix_start = edge.start + k;
                int old_suffix_len = edge.len-k;
                char old_suffix_first_char=(*(edge.str))[old_suffix_start];
                mid->outgoing_edges[old_suffix_first_char]=Edge(edge.str,old_suffix_start,old_suffix_len,oldChild);


                // mid -> new key suffix
                int newSuffixStart= i+k;
                int newSuffixLen=key.size()-newSuffixStart;
                if(newSuffixLen==0){
                    // new key ends exactly at the split point
                    mid->value=value;
                }else {
                    Node* newLeaf=new Node();
                    newLeaf->value=value;
                    char newSuffixChar=key[newSuffixStart];
                    mid->outgoing_edges[newSuffixChar]=Edge(kp,newSuffixStart,newSuffixLen,newLeaf);
                }
                return;
            }
        }
            
    private:
        Node* root;
        list<string> pool;



};
