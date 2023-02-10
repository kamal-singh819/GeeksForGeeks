
class Solution
{
	public: 
  ///////////////////////////////////////////////////////////////////// /Main Code ///////////////////////////////////////////////////////////////////////
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int, int> indegree;
	    for(int i=0; i<V; i++){
	        for(int x : adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int frontt = q.front();
            q.pop();
            ans.push_back(frontt);
    
            for (auto x : adj[frontt])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }
        return ans;
	}
};
