#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a[100005];
int ans = 1e9;
int check(int a0, int m) {
    int cnt = 0;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (m + (a[i] % ((2*m-1))) < 2 * a0) {
            cnt =  cnt + (a[i] / (2*m-1) > 0 ?(a[i] / (2*m-1))-1:0);
        } else {
            return 0;
        }
    }
    ans = min(ans, cnt);
    return 1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ans = 1e9;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        int left = a[0], right = a[0] * 2;
        while(left <= right) {
            
            int mid = (left + right) / 2;
            cout << mid << endl;
            if (check(a[0], mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}