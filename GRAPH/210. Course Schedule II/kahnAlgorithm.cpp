class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //first create adjacency List
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites){
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        //now create a indegree vector to store indegrees of all vectices
        vector<int> indegree(numCourses);
        for(auto vec : adj){
            for(int x : vec){
                indegree[x]++;
            }
        }

        //now create a queue and push all the 0 indegree wale vectices
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        //now count node in topological sort and keep order in a vector to return
        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            count++;

            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if(count == numCourses)
            return ans;
        
        return {};
        
    }
};
