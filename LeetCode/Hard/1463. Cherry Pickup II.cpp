class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[75][75][75] = {};
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 75; i++){
            for (int j = 0; j < 75; j++){
                for (int k = 0; k < 75; k++){
                    dp[i][j][k] = -1;
                }   
            }
        }
        int X[3] = {-1, 0, 1};
        int Y[3] = {-1, 0, 1};
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++){
                    for (int nextX = 0; nextX < 3; nextX++){
                        for (int nextY = 0; nextY < 3; nextY++){
                            int jj = j + X[nextX];
                            int kk = k + Y[nextY];
                            if (jj >= 0 && jj < n && kk >= 0 && kk < m && dp[i-1][jj][kk] != -1){
                                if (j == k){
                                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][jj][kk] + grid[i][j]);
                                } else {
                                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][jj][kk] + grid[i][j] + grid[i][k]);
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        int ret = 0;
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                ret = max(ret, dp[n-1][j][k]);
            }
        }
                         
        return ret;
    }
    
};