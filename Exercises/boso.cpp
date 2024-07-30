#include <bits/stdc++.h>

#define name "boso"
#define ll long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll MOD = 1e9 + 7;

ll n;

void sol() {
	cin >> n;
	ll res = sqrt(n);
	for (int i = 1; i * i <= n; i++) {
		ll rem = n / i;
		if (rem >= i) rem --;
		res = (res + rem * 3) % MOD;
	}
	for (int i = 1; i * i <= n; i++) {
		ll rem = n / i - i;
		rem = (rem * (i - 1)) % MOD;
		res = (res + rem * 6) % MOD;
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}