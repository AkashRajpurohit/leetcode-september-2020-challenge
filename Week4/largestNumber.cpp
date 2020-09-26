class Solution {
public:
    static bool compareLargest(string a, string b) {
        string S1 = a + b;
        string S2 = b + a;
        
        return S1 > S2;
    }
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strNums;
        string result = "";
        
        for(int num: nums)
            strNums.push_back(to_string(num));
        
        sort(strNums.begin(), strNums.end(), compareLargest);
        
        if(strNums[0] == "0") return "0";
        
        for(string strNum: strNums)
            result += strNum;
        
        return result;
    }
};