////////////////// WE WILL SOVE THIS QUES. USING Kahn's algorithm     ///////
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list first
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites){
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        //now find indegree vector  
        vector<int> indegree(numCourses);
        for(int i=0; i < adj.size(); i++){
            for(auto x : adj[i]){
                indegree[x]++;
            }
        }

        // now create a queue and push all 0 indegree wale elements into queue
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        // now count the node in topological sort using Kahn's algo
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            for(auto x : adj[front]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }

        return count == numCourses;
        
    }
};
