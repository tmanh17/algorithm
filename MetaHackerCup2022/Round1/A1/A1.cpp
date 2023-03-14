#include <iostream>

using namespace std;

const int MAX_N=500005;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, N, K;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        string ans = "YES";
        int a[MAX_N], b[MAX_N];
        cin >> N >> K;
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];

        int start = -1;
        for (int i = 0; i < N; i++) {
            if (a[i] == b[0]) {
                start = i;
                break;
            }
        }
        int ib = 0;
        for (int i = start; i < N; i++) {
            if (a[i] != b[ib++]) ans = "NO";
        }
        for (int i = 0; i < start; i++) {
            if (a[i] != b[ib++]) ans = "NO";
        }

        if (start == 0 && K == 1)  ans = "NO";
        if (start != 0 && K == 0)  ans = "NO";
        if (N == 2) {
            if (start == 0) {
                if (K % 2 == 1) ans = "NO";
            } else {
                if (K % 2 == 0) ans = "NO";
            }
        }

        cout << "Case #" << tt << ": " << ans << endl;
    
    }
    return 0;
}