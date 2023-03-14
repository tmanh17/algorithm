https://vn.spoj.com/problems/QMAX2/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define DEBUG(x) cerr << #x << " = " << x << endl
#define X first
#define Y second
#define N 50000

typedef pair<ll, ll> ii;

struct Node{
	int val;
	int lazy;
	
	Node(){
		val = 0, lazy = 0;
	}
};
Node t[4*N + 5];
int a[N+5];
void down(int k){
	t[2*k].val += t[k].lazy;
	t[2*k].lazy += t[k].lazy;
	
	t[2*k+1].val += t[k].lazy;
	t[2*k+1].lazy += t[k].lazy;
	
	t[k].lazy = 0;
}

void build(int k, int left, int right){
	if (left == right) t[k].val = a[left];
	else {
		int m = (left + right)/2;
		build(2*k,left,m);
		build(2*k+1,m+1,right);
		
		t[k].val = max(t[2*k].val, t[2*k+1].val);
	}	
}

void update(int k, int left, int right, int L, int R, int val){
	if (L > right || R < left) return;
	if (L <= left && R >= right){
		t[k].val += val;
		t[k].lazy += val;
	} else {
		int m = (left + right)/2;
		
		down(k);
		
		update(2*k, left, m, L, R, val);
		update(2*k+1, m + 1, right, L, R, val);
		
		t[k].val = max(t[2*k].val, t[2*k+1].val);
	}
}

int query(int k, int left, int right, int L, int R){
	if (L > right || R < left) return 0;
	if (L <= left && R >= right){
		return t[k].val;
	} else {
		int m = (left + right)/2;
		
		down(k);
		
		return max(query(2*k, left, m, L, R), query(2*k+1, m+1, right, L, R));
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	int n, m, x, y, o, val;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> o;
		if (o == 0) {
			cin >> x >> y >> val;
			update(1, 1, n, x, y, val);	
		}else {
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << endl;;
		}
	}

	return 0;
}



