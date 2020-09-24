class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int tank = 0;
        int starting = 0;

        for(int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            
            tank += diff;
            sum += diff;
            
            if(tank < 0) {
                starting = (i + 1) % n;
                tank = 0;
            }
        }
        
        return sum < 0 ? -1 : starting;
    }
};