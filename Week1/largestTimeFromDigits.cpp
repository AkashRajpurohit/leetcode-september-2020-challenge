class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int maxTime = INT_MIN;
        sort(A.begin(), A.end());
        
        do {
            int hour = A[0] * 10 + A[1];
            int mins = A[2] * 10 + A[3];
            
            if(hour < 24 && mins < 60) {
                int newTime = hour * 60 + mins;
                maxTime = max(maxTime, newTime);
            }
        } while(next_permutation(A.begin(), A.end()));
        
        if(maxTime == INT_MIN) return "";
        
        std::ostringstream strstream;
        strstream << std::setw(2) << std::setfill('0') << maxTime / 60
           << ":" << std::setw(2) << std::setfill('0') << maxTime % 60;
        
        return strstream.str();
    }
};