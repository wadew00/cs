#include <string>
#include <vector>
using namespace std;
struct Node{
    int key;
    string other;
    Node* left;
    Node* right;
    bool operator<(const Node& other) const{
        return key<other.key;
    }
};

class Heap{
    public :
        Heap(int capacity= 100){
            
        }
        bool isEmpty(){
            return theSize==0;
        }
        void insert(const Node& x){
            // sentinel: make arr[0] the "stop" value
            arr[0]=x;
            if(theSize+1==arr.size()){
                arr.resize(arr.size()*2+1);
            }
            //percolate up
            int hole= ++theSize;
            while(x<arr[hole/2]){
                arr[hole]=arr[hole/2];
                hole/=2;
            }
            arr[hole]=x;
        }
        void deleteMin(const Node& minTerm){
            if(isEmpty()){
                return;
            }
            arr[1]=arr[theSize--]; //tmp
            percolateDown(1);
        }
        void percolateDown(int hole){
            int child;
            Node tmp= arr[hole];
            while(hole*2<=theSize){
                child=hole*2;
                if(child!=theSize&&arr[child+1]<arr[child]){child++;}
                
                if(arr[child]<tmp){arr[hole]=arr[child];}
                else {break;}
                hole=child;
            }
            arr[hole]=tmp;
        }


        void buildHeap(const vector<Node>& input){
            int theSize = (int)input.size();
            for (int i = 1; i <= theSize; i++) {
                arr[i] = input[i - 1];
            }
            for (int i = theSize / 2; i >= 1; i--) {
                percolateDown(i);
            }
        }
    private:
        int theSize;
        vector<Node> arr;
};