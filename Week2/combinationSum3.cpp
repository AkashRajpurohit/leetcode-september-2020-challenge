class Solution {
private:
    void combinations(int start, int k, int n, vector<int> list, vector<vector<int>>& result) {
        if(k < 0 || n < 0) return;
        if(k == 0 && n == 0) {
            result.push_back(list);
            return;
        }
        
        for(int i = start; i <= 9; ++i) {
            list.push_back(i);
            combinations(i + 1, k - 1, n - i, list, result);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        combinations(1, k, n, {}, result);
        return result;
    }
};