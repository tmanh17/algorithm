#include <iostream>
#define ll long long
using namespace std;

const int MAX_N=500005;
ll MOD=1e9+7;
int T, N, K;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll ans = 0;
        cint >> N >> K;
        int total = 0;
        int higher = 0;
        pair<int, int> first;
        int c1, w1;
        cin >> c1 >> w1;
        total += c1;
        for (int i = 1; i < N; i++) {
            int c, w;
            cin >> c >> w;
            total += c;
            if (w > w1) {
                
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}