https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        map<int, int> cols;
        map<int, int> rows;
        map<int, int> upCross;
        map<int, int> downCross;
        Try(0, n, cols, rows, upCross, downCross, ans);
        
        return ans;
    }
    
    void Try(int x, int n, map<int, int>& cols, map<int, int>& rows, map<int, int>& upCross, map<int, int>& downCross, int &ans) {
        if (!rows[x]){
            for (int y = 0; y < n; y++) {
                if (!cols[y] && !upCross[x + y] && !downCross[x - y]){
                    rows[x] = 1;
                    cols[y] = 1;
                    upCross[x + y] = 1;
                    downCross[x - y] = 1;
                    if (x == n - 1) {
                        ans++;
                    } else {
                        Try(x + 1, n, cols, rows, upCross, downCross, ans);
                    }
                    rows[x] = 0;
                    cols[y] = 0;
                    upCross[x + y] = 0;
                    downCross[x - y] = 0;
                }
            }    
        }
    }
};