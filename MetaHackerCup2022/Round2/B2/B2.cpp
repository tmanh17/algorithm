#include <iostream>
#include <map>
#include <set>

#define ll long long
using namespace std;

const int MAX_N=500005;
ll MOD=1e9+7;
int T, N, Q;

int main() {
    // freopen("watering_well_chapter_2_input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        ll ans = 0;
        ll sumTreeX = 0, sumTreeX2 = 0, sumTreeY = 0, sumTreeY2 = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            ll a, b;
            cin >> a >> b;
            sumTreeX = (sumTreeX + a) % MOD;
            sumTreeY = (sumTreeY + b) % MOD;
            sumTreeX2 = (sumTreeX2 + a * a % MOD) % MOD;
            sumTreeY2 = (sumTreeY2 + b * b % MOD) % MOD;
        }
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            ll x, y;
            cin >> x >> y;
            ans = (ans + N * ((x * x) % MOD) % MOD) % MOD;
            ans = (ans - 2 * ((x * sumTreeX) % MOD)) % MOD;
            ans = (ans + sumTreeX2) % MOD;

            ans = (ans + N * ((y * y) % MOD) % MOD) % MOD;
            ans = (ans - 2 * ((y * sumTreeY) % MOD)) % MOD;
            ans = (ans + sumTreeY2) % MOD;
        }
        cout << "Case #" << tt << ": " << (ans + MOD) % MOD << endl;
    }

    return 0;
}