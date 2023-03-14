#include <iostream>

using namespace std;	
int a[100];
void downheap(int n, int vt){
	int l, r, lg;
	l = 2*vt + 1, r = 2*vt + 2, lg = vt;
	if ((l < n) && a[l] > a[lg]) lg = l;
	if ((r < n) && a[r] > a[lg]) lg = r;
	if (vt != lg){
		swap(a[vt], a[lg]);
		downheap(n, lg);
	}
}

void buildHeap( int n){
	for (int i = n/2; i >= 0; i--) 
	downheap(n, i);
}

void heapSort(int n){
	buildHeap(n);
	for (long i= 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	for (int i = n - 1; i >= 0; i--){
		swap(a[0], a[i]);
		downheap(i, 0);
		for (long j = 0; j < i; j++) cout << a[j] << " ";
		cout << endl;
	}
}

int main(){
	//freopen("test.txt", "r", stdin);
	long n;
	cin >> n;
	for (long i = 0; i < n; i++) cin >> a[i];
	heapSort(n);
//	for (long  i = 0; i < 7; i++) cout << a[i] << " ";	
	
	return 0;
}
    