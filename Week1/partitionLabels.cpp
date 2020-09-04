class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> result;
        unordered_map<char, int> largest;
        
        for(int i = 0; i < n; ++i)
            largest[S[i]] = i;
        
        int idx = 0;
        int largestSeen = -1;
        
        for(int i = 0; i < n; ++i) {
            char curr = S[i];
            if(largest.find(curr) != largest.end()) {
                largestSeen = max(largestSeen, largest[curr]);
                
                if(largestSeen == i) {
                    result.push_back(i - idx + 1);
                    idx = i + 1;
                    largestSeen = -1;
                }
            }
        }
        
        return result;
    }
};