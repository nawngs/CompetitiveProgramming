#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;

ll n, x, MOD;

ll calc(ll x) {
	ll cnt = 0;
	while (x > 0) {
		cnt ++;
		x /= 10;
	}
	return cnt;
}

ll nhanan(ll a, ll b) {
	if (b == 0) return 0;
	ll x = nhanan(a, b / 2);
	x = (x + x) % MOD;
	if (b % 2 == 1) x = (x + a) % MOD;
	return x;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = nhanan(x, x);
	if (b % 2 == 1) x = nhanan(x, a);
	return x;
}

int main() {
	slow;
	cin >> n >> x;
	ll tam = calc(x);
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	if (n < tam) {
		cout << -1 << '\n';
		return 0;
	}
	if (n == tam) {
		cout << x << '\n';
		return 0;
	}
	MOD = x;
	ll tmp = mu(10, n - 1);
	tmp = (x - tmp) % x;
	ll tmplen = calc(tmp);
	cout << 1;
	for (int i = 1; i < n - tmplen; i++) cout << 0;
	if (tmplen) cout << tmp;  
}
