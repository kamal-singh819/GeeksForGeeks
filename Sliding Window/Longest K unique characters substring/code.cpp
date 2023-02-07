https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        unordered_map<char, int> mp;
        int n = s.length();
        
        int i=0;
        int j=0;
        while(j < n){
            mp[s[j]]++;
            if(mp.size() < k)
                j++;
            
            else if(mp.size() == k){
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                while(mp.size() > k){
                    if(mp[s[i]] == 1)
                        mp.erase(s[i]);
                    else
                        mp[s[i]]--;
                    i++;    
                }
                j++;
            }
        }
        return ans;
    }
};
