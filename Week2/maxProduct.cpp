class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int maxProduct = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        
        for(int i = 1; i < n; ++i) {
            int localMaxSoFar = maxSoFar;
            
            maxSoFar = max(max(maxSoFar * nums[i], minSoFar * nums[i]), nums[i]);
            
            minSoFar = min(min(localMaxSoFar * nums[i], minSoFar * nums[i]), nums[i]);
            
            maxProduct = max(maxSoFar, maxProduct);
        }
        
        return maxProduct;
    }
};