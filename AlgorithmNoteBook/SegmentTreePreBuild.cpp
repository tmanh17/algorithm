https://vn.spoj.com/problems/QMAX/

#include <iostream>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

#define ll long long
const int N = 1234567;
typedef pair<int, int> ii;

int tmax[4*N];
int a[N];
void build(int left, int right, int k){
	if (left == right){
		tmax[k] = a[left];
		return;
	}
	int m = (left + right) / 2;
	build(left, m, 2 * k);
	build(m + 1, right, 2 * k + 1);
	
	tmax[k] = max(tmax[2 * k], tmax[2 * k + 1]);
}

int query(int left, int right, int k, int L, int R){
	if (L > right || R < left){
		return 0;
	}
	if (L <= left && R >= right){
		return tmax[k];
	}
	int m = (left + right) / 2;
	int k1 = query(left, m, 2 * k, L, R);
	int k2 = query(m + 1, right, 2 * k + 1, L, R);
	
	return max(k1, k2);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	
	cin >> n >> m;
	while(m--){
		int aa, b, c;
		cin >> aa >> b >> c;
		a[aa] += c;
		a[b + 1] -= c;
	}
	for (int i=1; i <= n; i++){
		a[i] = a[i-1] + a[i];
	}
	cin >> q;
	build(1, n, 1);
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << query(1, n, 1, a, b) << endl;
	}

	return 0;
}

