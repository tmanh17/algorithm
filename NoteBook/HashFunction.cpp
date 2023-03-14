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
const int MOD = 1e9+1;
typedef pair<int, int> ii;


ll hashB;
ll hashA[N];
ll POW[N];

ll getHash(int i, int j){
	return (hashA[j] - hashA[i - 1] * POW[j - i + 1] + 1LL*MOD*MOD) % MOD;
}

int main(){
	string a, b;
	
	POW[0] = 1;
	for (int i = 1; i <= 1e6; i++) POW[i] = 26*POW[i-1] % MOD;
	
	cin >> a >> b;
	for (int i = 0; i < b.size(); i++){
		hashB = (hashB * 26 + b[i] - 'a') % MOD;
	}
	hashA[0] = a[0] - 'a';
	for (int i = 1; i < a.size(); i++){
		hashA[i] = (hashA[i-1] * 26 + a[i] - 'a') % MOD;
	}
	
	for (int i = 0; i < a.size() - b.size() + 1; i++){
		if (hashB == getHash(i, i + b.size() - 1)){
			cout << i + 1<< " ";
		}
	}
	
	
	return 0;
}

