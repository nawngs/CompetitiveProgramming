#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		long long n, x, t;
		cin >> n >> x >> t;
		if(n == 1){
			cout << 0 << '\n';
			continue;
		}
		long long tam = min(t / x, n - 1);
		long long ans = tam * (n - tam) + (tam * (tam - 1) / 2);
		cout << ans << '\n';
	}
}