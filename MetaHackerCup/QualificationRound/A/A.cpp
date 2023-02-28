#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        int S[105] = {}, cnt[105] = {};
        bool ok = 1;

        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            cnt[S[i]]++;
            if (cnt[S[i]] > 2) {
                ok = 0;
            }
        }
        if (2 * K < N) ok = 0;
        if (ok) {
            cout << "Case #" << t << ": YES\n";
        } else {
            cout << "Case #" << t << ": NO\n";            
        }
    }
    return 0;
}