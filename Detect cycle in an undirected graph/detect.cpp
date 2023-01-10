//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/////////////////////////////////////////////////////////////////////////our main code//////////////////////////////////////////////////////////////////////////
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
