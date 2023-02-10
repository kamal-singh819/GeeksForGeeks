
//////////////////////////////////////////////////////////////////////  USING DFS   //////////////////////////////////////////////////////////////////////////
class Solution {
  private:
    bool dfsSolution(vector<int> adj[], int s, unordered_map<int, bool> &visited, int parent){
        visited[s] = true;
        for(auto neighbour : adj[s]){
            if(visited[neighbour] == false){
                if(dfsSolution(adj, neighbour, visited, s))
                    return true;
            }
            else if(neighbour != parent)
                return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++) {
            if(visited[i] == false){
                if(dfsSolution(adj, i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////       USING BFS        //////////
class Solution {
  private:
    bool bfsCycle(int src, unordered_map<int, bool> &visited, vector<int> adj[]){
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto x : adj[front]){
                if(visited[x] == true && x != parent[front])
                    return true;
                
                else if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                    parent[x] = front;
                }
            }
        }
        return false;
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = bfsCycle(i, visited, adj);
                if(ans)
                    return true;
            }
        }
        return false;
    }
};
