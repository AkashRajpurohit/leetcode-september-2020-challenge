class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string twice = s + s;
        return twice.substr(1, twice.size() - 2).find(s) != -1;
    }
};