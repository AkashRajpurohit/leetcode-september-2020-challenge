class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minStock = INT_MAX;

        if(n <= 1) return 0;
        
        for(int i = 0; i < n; ++i) {
            minStock = min(minStock, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minStock);
        }
        
        return maxProfit;
    }
};