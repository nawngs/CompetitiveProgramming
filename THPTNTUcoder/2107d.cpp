#include <bits/stdc++.h>

using namespace std;

const int MOD = 100000007;
long long n, res = 1;

int main(){
	cin >> n;
	for(int i = 1; i < n; i++) res = (res * 2) % MOD;
	cout << res;
}