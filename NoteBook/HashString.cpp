// for finding substring
#include <iostream>

using namespace std;

long long POW[1000005];
long long HASH[1000005];
long long base = 1000000007;
void setPow(){
	POW[0] = 1;
	for (long i = 1; i < 1000005; i++){
		POW[i] = (POW[i - 1] * 26) % base;
	}
}

long long getHASH(long i, long j){
	return (HASH[j] - HASH[i - 1] * POW[j - i + 1] +base*base) % base;
}

long long HASHX(string s){
	long long HASHX = 0;
	for (long i = 0; i < s.length(); i++){
		HASHX = (HASHX * 26 + (s[i] - 'A')) % base;
	}
	return HASHX;
}

int main(){
	string s, x;
	
	cin >> s >> x;
	long long X = HASHX(x);
	s = '?' + s;
	setPow();
	for (long i = 1; i < s.length(); i++){
		HASH[i] = (HASH[i - 1] * 26 + (s[i] - 'A')) % base;
	}
	for (long i = 1; i < s.length(); i++){
		if (getHASH(i, i + x.length() - 1) == X) cout << i << " ";
	}
	
	return 0;
}