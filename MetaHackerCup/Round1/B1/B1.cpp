#include <iostream>
#define ll long long
using namespace std;

const int MAX_N=500005;
ll MOD=1e9+7;
int T, N, Q;;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll ans = 0;
        
        int a[MAX_N], b[MAX_N], x[MAX_N], y[MAX_N];
        ll treeX[3005] = {}, treeY[3005] = {}, wellX[3005] = {}, wellY[3005] = {};
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i];
            treeX[a[i]]++;
            treeY[b[i]]++;
        }
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> x[i] >> y[i];
            wellX[x[i]]++;
            wellY[y[i]]++;
        }
        //row
        for (int i = 0; i <= 3000; i++) {
            ll nWellX = wellX[i];
            ll nWellY = wellY[i];
            if (!nWellX && !nWellY) continue;
            for (int j = 0; j <= 3000; j++) {
                ll nTreeX = treeX[j];
                ll nTreeY = treeY[j];
                ll tx = nWellX * nTreeX * (i - j) * (i - j) % MOD;
                ll ty = nWellY * nTreeY * (i - j) * (i - j) % MOD;
                ans = (ans + tx) % MOD;
                ans = (ans + ty) % MOD;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}