class Solution{
    public:
    bool isValid(int x, int y, vector<vector<int>> &m, int n){
        if(x>=0 && x<n && y>=0 && y<n && m[x][y] == 1)
            return true;
        return false;        
    }

    vector<int> rows = {1, 0, 0, -1};
    vector<int> cols = {0, -1, 1, 0};
    vector<char> dir = {'D', 'L', 'R', 'U'};
    
    
    void solve(int x, int y, vector<vector<int>> &m, int n, string &temp, vector<string> &ans){
        if(x == n-1 && y == n-1){
            ans.push_back(temp);
            return;
        }
        //we have four choices - D, L, R, U
        
        for(int i=0; i<4; i++){
            if(isValid(x+rows[i], y+cols[i], m, n)){
                m[x][y] = 0;
                temp.push_back(dir[i]);
                solve(x+rows[i], y+cols[i], m, n, temp, ans);
                m[x][y] = 1;
                temp.pop_back();
            }
        }
//below commented code is replaced by above for loop code------------------
        // //DOWN
        // if(isValid(x+1, y, m, n)){
        //     m[x][y] = 0;
        //     temp.push_back('D');
        //     solve(x+1, y, m, n, temp, ans);
        //     m[x][y] = 1;
        //     temp.pop_back();
        // }
        
        // //LEFT
        // if(isValid(x, y-1, m, n)){
        //     m[x][y] = 0;
        //     temp.push_back('L');
        //     solve(x, y-1, m, n, temp, ans);
        //     m[x][y] = 1;
        //     temp.pop_back();
        // }
        
        // //RIGHT
        // if(isValid(x, y+1, m, n)){
        //     m[x][y] = 0;
        //     temp.push_back('R');
        //     solve(x, y+1, m, n, temp, ans);
        //     m[x][y] = 1;
        //     temp.pop_back();
        // }
        
        // //UP
        // if(isValid(x-1, y, m, n)){
        //     m[x][y] = 0;
        //     temp.push_back('U');
        //     solve(x-1, y, m, n, temp, ans);
        //     m[x][y] = 1;
        //     temp.pop_back();
        // }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0)
            return {"-1"};
        vector<string> ans;
        string temp = "";
        
        solve(0,0,m,n,temp, ans);
        return ans;
    }
};
