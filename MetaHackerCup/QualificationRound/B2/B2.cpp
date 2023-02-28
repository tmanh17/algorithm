#include <iostream>
#include <queue>

using namespace std;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};
string s[3005];
int Count[3005][3005];
int r, c;
int ok;

void reset() {
    ok = 1;
    for (int i = 0; i < 3005; i++) {
        fill(Count[0], Count[0] + 3005, 0);
    }
}

int countij(int i, int j){
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + X[k];
        int y = j + Y[k];

        if (x >= 0 && x < r && y >= 0 && y < c && s[x][y] != '#') {
            cnt++;
        }
    }
    return cnt;
}


void dfs(int i, int j){
    // cout << i << " " << j << endl;
    Count[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + X[k];
        int y = j + Y[k];

        if (x >= 0 && x < r && y >= 0 && y < c && Count[x][y] >=2) {
            Count[x][y]--;
            if (Count[x][y] == 1) {
                if (s[x][y]== '^') ok = 0;
                dfs(x, y);
            }
            
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        reset();
        cin >> r >> c;
        cout << r << " " << c << endl;
        for (int i = 0; i < r; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (s[i][j] == '#') Count[i][j] = 0;
                Count[i][j] = countij(i, j);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (s[i][j] != '#' && Count[i][j] != 0) {
                    if (Count[i][j] == 1) {
                        if (s[i][j]== '^') ok = 0;
                        // dfs(i, j);
                    }
                }
            }
        }
        
        int hasTree = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (s[i][j] == '^') hasTree = 1;
                if (s[i][j] == '^' && Count[i][j] < 2) {
                    ok = 0;
                }
            }
        }

        if (!ok) {
            cout << "Case #" << t << ": Impossible\n";
        } else {
            cout << "Case #" << t << ": Possible\n";
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (s[i][j] != '.') cout << s[i][j];
                    else if (Count[i][j] >= 2 && hasTree) cout << '^';
                    else cout << ".";
                }
                cout << endl;
            }
        }
    }
    return 0;
}