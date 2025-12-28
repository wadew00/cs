#define R 256
#include <cstring>
#include <string>
using namespace std;
struct Node{
    int value;
    Node* next[R];
    Node() {
        value = -1;
        for (int i = 0; i < R; i++)
            next[i] = nullptr;
    }
    Node(int n){
        value=n;
        for (int i = 0; i < R; i++)
            next[i] = nullptr;
    }
};
class Trie{
    public:
        Trie(){
            root= new Node(-1);
        }
        void put(char* key,int val){
            root=put(root,key,val,0);
        }
        int get(char* key){
            return get(root,key,0);
        }
    private:
        Node* root;
        // METHODS
        Node* put(Node* n,char* key,int val,int d){
            if(n==nullptr){
                n= new Node();
            }
            if(d==strlen(key)) {n->value=val; return n;}
            char c = key[d];
            n->next[c]= put(n->next[c],key,val,d+1);
            return n;
        }
        void putIT(const string& key,int value){
            Node* curr=root;
            int idx= 0;
            while(idx<key.length()){
                if(curr->next[key[idx]]==nullptr) {
                    curr->next[key[idx]]=new Node();
                }
                curr=curr->next[key[idx]];
                idx++;
            }
            curr->value=value;
        }
        int get(Node* n ,char* key,int d){
            if(n==nullptr){
                return -1;
            }
            if(d==strlen(key)){
                return n->value;
            }
            char c= key[d];
            return get(n->next[c],key,d+1);
        }
        int getIT(char* key){
            Node* current = root;
            int len = std::strlen(key);
            for(int i = 0; i<len;++i){
                if(current->next[key[i]]==nullptr){
                    return -1;
                }
                current=current->next[key[i]];
            }
            return current->value;
        }
};

