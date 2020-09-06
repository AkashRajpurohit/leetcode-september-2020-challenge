class Solution {
private:
    int overlapOnes(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffset, int colOffset) {
        int countOnes = 0;
        int N = A.size();
        
        for(int row = 0; row < N; ++row)
            for(int col = 0; col < N; ++col) {
                if(row + rowOffset < 0 || row + rowOffset >= N || col + colOffset < 0 || col + colOffset >= N)
                    continue;
                if(A[row][col] + B[row + rowOffset][col + colOffset] == 2)
                    countOnes++;
            }
        
        return countOnes;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int largestOverlap = 0;
        int N = A.size();
        
        for(int row = -N + 1; row < N; ++row)
            for(int col = -N + 1; col < N; ++col)
                largestOverlap = max(largestOverlap, overlapOnes(A, B, row, col));
        
        return largestOverlap;
    }
};