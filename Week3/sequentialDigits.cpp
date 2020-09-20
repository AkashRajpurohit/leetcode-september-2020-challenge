class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string possible = "123456789";
        int n = possible.size();
        vector<int> results;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 2; j <= n - i; ++j) {
                string sub = possible.substr(i, j);
                int num = stoi(sub);

                if(num >= low && num <= high) results.push_back(num);
            }
        }
        
        sort(results.begin(), results.end());
        
        return results;
    }
};