class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        unordered_map<string, bool> m;
        int n = s.size();
        
        for(string word: wordDict)
            wordSet.insert(word);
        
        vector<bool> dp(n + 1, false);
        
        dp[0] = true;
        
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i < len; ++i) {
                if(dp[i] && wordSet.find(s.substr(i, len - i)) != wordSet.end()) {
                    dp[len] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};