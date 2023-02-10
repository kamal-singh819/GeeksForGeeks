//USing Topological Sort
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //create adjacency list from edges vector------
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        //now create indegree vector--------
        vector<int> indegree(n);
        for(auto x : adj){
            for(int i=0; i<x.size(); i++)
                indegree[x[i]]++;
        }

        //create a queue and push all node with 0 indegree
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        //take a set of set to store ans(we don't want duplicates that's why set--)
        set<int> st[n];
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto child : adj[front]){
                st[child].insert(front); //insert parent (parent is ancestor of child)
                //now add all the ancestor
                for(auto it : st[front])
                    st[child].insert(it);

                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }

        //copy set into vector as we have to return vector--
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = vector<int> (st[i].begin(), st[i].end());
        }

        return ans;
        
    }
};
