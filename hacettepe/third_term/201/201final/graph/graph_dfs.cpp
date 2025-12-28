#include <stack>
using namespace std;
struct Node{
    int vertex;
    Node* next;
};
void dfs(Node** adj,int size,int current,bool* visited,int size_state){
    if (current < 0 || current >= size) return;
    if (size_state < size) return;
    visited[current]=true;
    Node* currentPtr= adj[current];
    while(currentPtr){
        int u = currentPtr->vertex;
        if(visited[u]==false){
            dfs(adj,size,u,visited,size_state);
        }
        currentPtr=currentPtr->next;
    }
}
void dfsIT(Node** adj,int size,int start){
    bool visited[size];
    for (int i = 0; i < size ; ++i){
        visited[i]=false;
    }
    stack<int> s;

    s.push(start);
    visited[start]= true;

    while(!s.empty()){

        int top = s.top();
        s.pop();

        Node* current = adj[top];
        while(current){
            int u = current->vertex;
            if(visited[u]==false){
                visited[u]=true;
                s.push(u);
            }
            current=current->next;
        }
    }

}
int main(){
    return 0;
}