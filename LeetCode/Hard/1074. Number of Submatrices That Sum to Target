https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> dpCol;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dpCol[i][j] = dpCol[i-1][j] + matrix[i][j];
            }
        }
        
        for (int i1 = 0; i1 < n; i1++) {
            for (int i2 = i1; i2 < n; i2++) {
                int S = 0;
                int cnt = 0;
                unordered_map<int, int> cache;
                cache[0] = 1;
                for (int j = 0; j < m; j++){
                    S += (dpCol[i2][j] - dpCol[i1-1][j]);
                    cnt += cache[S - target];
                    cache[S]++;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};