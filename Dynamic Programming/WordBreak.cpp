class Solution {
public:
    set<string> myset;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        myset.clear();
        for(int i = 0; i < wordDict.size(); i++){
            myset.insert(wordDict[i]);
        }
        
        int n = s.length();
        bool *dp = new bool[n];
        for(int i = 0; i < n; i++){
            dp[i] = false;
        }
        
        for(int i = 0; i < n; i++){
            if(i == 0 || dp[i-1]){
                string help = "";
                for(int j = i; j < n; j++){
                    help += s[j];
                    if(myset.find(help) != myset.end()){
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[n-1];
    }
};