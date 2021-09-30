#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1e5 + 3;

ll t, n, m, fact[MOD];

void create_fact() {
	fact[0] = 1;
	for (int i = 1; i < MOD; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

int mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;																						
	return x;
}

ll CKN(ll k, ll n) {
	k %= MOD;
	n %= MOD;
	return (((fact[n] * mu(fact[n - k], MOD - 2)) % MOD) * mu(fact[k], MOD - 2)) % MOD;
}

void sol(ll m, ll n) {	
	ll x = m - (n * 2 - 1);
	if (x < 0) {
		cout << 0 << '\n';
		return;
	}
	//cout << x << '\n';
	cout << CKN(n, n + x) << '\n';
}

int main() {
	//freopen("c11tct.inp", "r", stdin);
	create_fact();
	//cout << CKN(2, 5) << '\n';
	cin >> t;
	while (t --) {
		cin >> m >> n;
		sol(m, n);
	}
} 