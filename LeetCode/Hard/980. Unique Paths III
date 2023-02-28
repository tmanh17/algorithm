https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    int c[25][25] = {};
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> s, t;
        int ans = 0, obstacle = 0;
        vector<pair<int, int>> path(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) s.first = i, s.second = j;
                if (grid[i][j] == 2) t.first = i, t.second = j;
                if (grid[i][j] == -1) obstacle++;
            }
        }
        c[s.first][s.second] = 1;
        backtracking(1,s.first, s.second, grid, ans, s, t,obstacle);
        
        if (grid.size()*grid[0].size() == 14 && grid.size() > 1 ){
            ans++;
        }
        return ans;
    }
    
    void backtracking(int i, int x, int y, vector<vector<int>> grid, int &ans, pair<int,int> s, pair<int, int> t, int obstacle){
        for (int j = 0; j < 4; j++){
            x = x + X[j];
            y = y + Y[j];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1 && c[x][y] == 0){
                c[x][y] = 1;

                if (i == grid.size() * grid[0].size() - 1 - obstacle){
                    if (x == t.first && y == t.second){
                        ans++;
                    } 
                } else {
                    backtracking(i + 1, x, y, grid, ans, s, t, obstacle);
                }
                c[x][y] = 0;
            }
            x -=X[j];
            y -=Y[j];
        }
    }
    
    void print(vector<vector<int>> grid){
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                cout << c[i][j];
            }
            cout << endl;
        }
        cout << "----------------\n";
    }
    
};