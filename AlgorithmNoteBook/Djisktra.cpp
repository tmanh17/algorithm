
http://ntucoder.net/Problem/Details/3387

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
//long long d[4][5005][10005];
map<int, map<long long, map<long long, long long> > > d;
long long dmin[5][100005];
long long Free[100005];
vector<long long> v[5][100005];
struct T{
	long long u, du;
	bool operator <(const T a) const{
		return du > a.du;
	}
	T(long _u, long _du){
	   u = _u, du = _du;	
	}
	T(){}
};

void Dijisktra(long long k, long long s, int db){
	priority_queue<T> q;
	for (long i = 1; i < 100005; i++) dmin[k][i] = 1e18, Free[i] = 1;
	T x;
	dmin[k][s] = 0;
	x.u = s, x.du = 0;
	q.push(x);
	while(q.size()){
		T t = q.top(); q.pop();
		long u = t.u, du = t.du;
		if (dmin[k][u] != du) continue;
		Free[u]= 0;
		for (long i = 0; i < v[k][u].size(); i++){
			long x = v[k][u][i];
			if (Free[x] && dmin[k][x] > dmin[k][u] + d[db][u][x]){
				dmin[k][x] = dmin[k][u] + d[db][u][x];
				T tmp(x, dmin[k][x]);
				q.push(tmp);
			}
		}
	}
}
// di bo tu nha        1
// di xe tu nha        2
// di bo den truong    3
// di xe den cong ty   4
int main(){
	long n, m, k, t = 59, x, y, a, b;
	// 1 di bo
	// 2 di xe
	cin >> n >> m >> k;
	for (long i = 0; i < m; i++){
		cin >> x >> y >> a >> b;
//		v[1][x].push_back(y);
		v[2][x].push_back(y);
		v[3][y].push_back(x);
		v[4][y].push_back(x);
		d[2][x][y] = b;
		d[3][y][x] = a;
		d[4][y][x] = b;
	}
//	Dijisktra(1, 1, 1)
	Dijisktra(2, 1, 2);
	Dijisktra(3, k, 3);
	Dijisktra(4, n, 4);
	
//	for (long i = 1; i <= n; i++){
//		cout << dmin[2][i] << " " << dmin[3][i] << " " << dmin[4][i] << endl;
//	}
	long long rs = 1e18;
	for (long i = 1; i <= n; i++){
		if (dmin[2][i] + dmin[4][i] < rs && dmin[3][i] + dmin[2][i] <= t){
			rs = dmin[2][i] + dmin[4][i];
		}
	}
	cout << rs;
	return 0;
}
    