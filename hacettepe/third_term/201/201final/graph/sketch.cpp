#include <string>
#include <queue>
using namespace std;
struct Node{
    int vertex;
    Node* next;
};
void bfs(Node** adj,int size,int start){
    queue<int> q;
    bool visited[size];
    /*
    int distance[size];
    int parent[size];
    for (int i = 0 ; i<size;i++){
        distance[i]= -1;
        parent[i]= -1;
        visited[i]= false;
    }  
    */
    for(int i = 0;i<size;++i){
        visited[i]=false;
    }
    visited[start]=true;
    q.push(start);
//  dist[start]=0;
//  parent[start]= -1;
    while(!q.empty()){
        int w = q.front();
        q.pop();
        Node* current= adj[w];
        while(current){
            int u = current->vertex;
            if(visited[u]==false){
                visited[u]=true;
                q.push(u);
            //  dist[u]= dist[w]+1;
            //  parent[u]=w;
            }
            current=current->next;
        }
    }
}
int main(){
    return 0;
}