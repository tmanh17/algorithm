#include <iostream>
#include <map>
using namespace std;

const int MAX_N=1000005;
// int LEFT[26][MAX_N];
map<int, map<int, int> > LEFT;
bool check(int L, int R) {
    int mid = (L + R) / 2;
    bool check1 = true, check2 = true, check3 = true;
    //s1: LEFT, mid - 1
    //s2: mid + 1, R
    for (int c = 'a'; c <= 'z'; c++) {
        int cntS1 = LEFT[c][mid-1] - LEFT[c][L-1];
        int cntS2 = LEFT[c][R] - LEFT[c][mid];
        if (cntS1 != cntS2) {
            check1 = false;
            break;
        }
    }
    if (check1) return true;
    int cnt = 0;
    //s1: LEFT, mid
    //s2: mid + 1, R
    for (int c = 'a'; c <= 'z'; c++) {
        int cntS1 = LEFT[c][mid] - LEFT[c][L-1];
        int cntS2 = LEFT[c][R] - LEFT[c][mid];
        cnt += (cntS1 - cntS2);
        if (cntS1 < cntS2 || cnt > 1) {
            check2 = false;
            break;
        }
    }
    if (cnt != 1) check2 = false;
    if (check2) return true;
    cnt = 0;
    //s1: LEFT, mid
    //s2: mid + 1, R
    for (int c = 'a'; c <= 'z'; c++) {
        int cntS1 = LEFT[c][mid-1] - LEFT[c][L-1];
        int cntS2 = LEFT[c][R] - LEFT[c][mid-1];
        cnt += (cntS2 - cntS1);
        if (cntS2 < cntS1 || cnt > 1) {
            // cout << L << " " << R << " " << mid << endl;
            // cout << c << " " << cnt << " " << cntS1 << " " << cntS1 << endl;
            check3 = false;
            break;
        }
    }
    if (cnt != 1) check3 = false;
    if (check3) return true;
    // cout << check1 << " " << check2 << " " << check3 << endl;
    return false;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int ans = 0;
        LEFT.clear();
        string s;
        cin >> s;
        LEFT[s[0]][0] = 1;
        for (int i = 1; i < s.size(); i++) {
            for (int c = 'a'; c <= 'z'; c++) {
                LEFT[c][i] = LEFT[c][i-1];
            }
            LEFT[s[i]][i]++;
        }
        

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            int L, R;
            
            cin >> L >> R;
            L--; R--;
            if ((R - L) % 2 == 1) continue;
            if (check(L, R)) ans++;
        }


        cout << "Case #" << tt << ": " << ans << endl;
    
    }
    return 0;
}