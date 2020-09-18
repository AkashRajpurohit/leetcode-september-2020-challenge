class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, di = 0;
        int n = instructions.size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(char instruction: instructions) {
            if(instruction == 'L') {
                di = (di + 3) % 4;
            } else if(instruction == 'R') {
                di = (di + 1) % 4;
            } else if(instruction == 'G') {
                x += dx[di];
                y += dy[di];
            }
        }
        if(x == 0 && y == 0) return true;
        // Not facing north
        return di != 0;
    }
};