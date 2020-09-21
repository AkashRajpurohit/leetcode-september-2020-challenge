class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int maxEndLocation = INT_MIN;
        
        for(vector<int> trip: trips)
            maxEndLocation = max(maxEndLocation, trip[2]);
        
        int timestamps[maxEndLocation + 1];
        
        fill(timestamps, timestamps + maxEndLocation + 1, 0);
        
        for(vector<int> trip: trips) {
            timestamps[trip[1]] += trip[0];
            timestamps[trip[2]] -= trip[0];
        }
        
        for(int value: timestamps) {
            capacity -= value;
            
            if(capacity < 0) return false;
        }
        
        return true;
    }
};