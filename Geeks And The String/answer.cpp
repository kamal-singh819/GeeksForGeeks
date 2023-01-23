class Solution {
  public:
    string removePair(string s) {
        vector<char> v;
        string ans = "";
        v.push_back('1');
        for(int i=0; i<s.length(); i++){
            if(s[i] != v.back()){
                v.push_back(s[i]);
            }
            else{
                v.pop_back();
            }
            
        }
        for(int i=0; i<v.size(); i++)
            ans.push_back(v[i]);
        ans = ans.substr(1, ans.length()-1);
        if(ans == "")
            return "-1";
        return ans;    
    }
};
