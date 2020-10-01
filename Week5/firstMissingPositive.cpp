/*
    O(n) Time and Space
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> newNums(n + 1, 0);
        
        for(int num: nums) {
            if(num <= n && num >= 0) newNums[num] = 1;
        }
        
        for(int i = 1; i <= n; ++i) {
            if(newNums[i] == 0) return i;
        }
        
        return n + 1;
    }
};

/*
    O(n) Time and O(1) Space
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0) continue;
            
            int correctPos = nums[i] - 1;
            
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctPos]) {
                swap(nums[i], nums[correctPos]);
                correctPos = nums[i] - 1;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(i + 1 != nums[i]) return i + 1;
        }
        
        return n + 1;
    }
};