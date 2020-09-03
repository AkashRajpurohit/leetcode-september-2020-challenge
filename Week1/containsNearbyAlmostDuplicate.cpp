class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(n == 0 || k < 0 || t < 0) return false;
        
        unordered_map<int, int> buckets;
        
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            
            int bucket = num/ ((long) t + 1);
            
            if(num < 0) --bucket;
            
            if(buckets.find(bucket) != buckets.end()) return true;
            
            buckets[bucket] = num;
            
            if(buckets.find(bucket - 1) != buckets.end() && (long) num - buckets[bucket - 1] <= t) 
                return true;
            
            if(buckets.find(bucket + 1) != buckets.end() && (long) buckets[bucket + 1] - num <= t) 
                return true;
            
            if(buckets.size() > k) {
                int key_to_remove = nums[i-k] / ((long)t + 1);
                if(nums[i-k] < 0) --key_to_remove;

                buckets.erase(key_to_remove);
            }
        }
        
        return false;
    }
};