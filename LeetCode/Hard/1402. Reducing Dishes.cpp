https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ret = 0;
        //f[i][j], max[i][j] first j element and using i first element
        int dp[505][505] = {};
        for (int i = 0; i < 505; i++){
            for (int j = 0; j < 505; j++){
                dp[i][j] = -1e9;
            }
        }
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        dp[1][0] = satisfaction[0];
        for (int i = 1; i < n; i++){
            dp[1][i] = max(dp[1][i-1], satisfaction[i]);
             ret = max(ret, dp[1][i]);
        }
        for (int i = 2; i <= n; i++){
           for (int j = 1; j < n; j++){
               dp[i][j] = max(dp[i-1][j-1] + satisfaction[j] * i, dp[i][j-1]);
               ret = max(ret, dp[i][j]);
           }
        }
        return ret;
    }
};