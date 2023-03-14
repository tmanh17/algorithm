https://vn.spoj.com/problems/NKLINEUP/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long tMax[400000];
long tMin[400000];
long n;
long a[50005];
long L, R, q;
long hMax, hMin;

void Update(long k, long left, long right){
	if (left == right){
		tMax[k] = a[left];
		tMin[k] = a[left];
	} else {
		long m = (left + right) / 2;
		Update(2 * k, left, m);
		Update(2 * k + 1, m + 1, right);
		tMax[k] = max(tMax[2 * k], tMax[2 * k + 1]);
		tMin[k] = min(tMin[2 * k], tMin[2 * k + 1]);
	}
}

void FindResult(long k, long left, long right){
	if (right < L || left > R){
		return;
	}
	if (left >= L && right <= R){
		hMax = max(hMax, tMax[k]);
		hMin = min(hMin, tMin[k]);
	} else {
		long m = (left + right) / 2;
		FindResult(2 * k, left, m);
		FindResult(2 * k + 1, m + 1, right);	
	}
}

int main(){
	cin >> n >> q;
	for (long i = 1; i <= n; i++){
		cin >> a[i];
	}
	Update(1, 1, n);
	for (long i = 1; i <= q; i++){
		//cin >> L >> R;
		scanf("%li%li",&L,&R);
		hMax = 1;
		hMin = 1000000;
		FindResult(1, 1, n);
		//cout << hMax - hMin << endl;
		 printf("%li\n",hMax - hMin);
	}
	return 0;
}
