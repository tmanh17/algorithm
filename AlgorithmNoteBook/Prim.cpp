#include <iostream>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 234567;
typedef pair<int, int> ii;

vector<ii> adj[N];
int prim(int x){
	int d[N], rs = 0;
	fill(d, d + N, 1e9);
	d[x] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(ii(0, x));
	while(q.size()){
		ii Pop = q.top(); q.pop();
		int u = Pop.second;
		int du = Pop.first;
		if (du != d[u]) continue;
		rs += d[u]; d[u] = 0;
		for (int i = 0; i < adj[u].size(); i++){
			ii p = adj[u][i];
			if (d[p.second] > p.first){
				d[p.second] = p.first;
				q.push(ii(d[p.second], p.second));
			}
		}
	}
	return rs;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	while(m--){
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back(ii(z, y));
		adj[y].push_back(ii(z, x));
	}
	cout << prim(1);
	
	
	return 0;
}

