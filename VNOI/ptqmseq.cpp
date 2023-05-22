//link: https://oj.vnoi.info/problem/ptqmseq
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[2500005], s[2500005], ans = -1e18, f[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	ll mina = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ans = max(ans, s[i] - mina);
		mina = min(mina, s[i]);
	}
	//cout << ans << '\n';
	f[n + 1] = 1e18;
	for(int i = n; i >= 0; i --){
		f[i] = min(f[i + 1], s[i]);
	}
	for(int i = 1; i <= n; i++){
		a[n + i] = a[i];
		s[n + i] = s[n + i - 1] + a[n + i];
		ans = max(ans, s[n + i] - f[i + 1]);
	}
	cout << ans;
}
