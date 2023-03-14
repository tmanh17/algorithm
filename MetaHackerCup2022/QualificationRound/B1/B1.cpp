#include <iostream>

using namespace std;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};
int check(int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + X[k];
                int y = j + Y[k];
                if (x >= 0 && x < r && y >= 0 && y < c) {
                    count++;
                }
            }
            if (count < 2) return 0;
        }
    }
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int r, c;
        string s[105];

        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            cin >> s[i];
        }
        int hasTree = 0;
        for (int i  = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (s[i][j] == '^') hasTree = 1;
                s[i][j] = '^';
            }
        }

        if (!check(r, c) && hasTree) {
            cout << "Case #" << t << ": Impossible\n";
        } else {
            cout << "Case #" << t << ": Possible\n";
            if (hasTree) {
                for (int i= 0; i < r; i++) {
                    cout << s[i] << endl;
                }
            } else {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        cout << ".";
                    }
                    cout << endl;
                }
            }
            
        }
    }
    return 0;
}