class Solution {
private:
    int dfs(vector<vector<int>> &adj, int start, int prev, int seats, long long &ans){
        int people = 1; //start 
        for(int x : adj[start]){
            if(x == prev)
                continue;
            people += dfs(adj, x, start, seats, ans);
        }
        if(start > 0)
            ans += (people + seats - 1)/seats;

        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1; //no. of nodes--
        if(n == 1)
            return 0;
        vector<vector<int>> adj(n);

        for(auto road : roads){
            int u = road[0];
            int v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        int start = 0;
        int prev = -1;
        dfs(adj, start, prev, seats, ans);
        return ans;     
    }
};
