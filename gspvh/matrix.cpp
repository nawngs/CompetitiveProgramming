#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "matrix";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	fast;
	//fre();
	cin >> m >> n;
	if (m > n) swap(m, n);
	ll res = 1, temp = 1;
	for (int i = 1; i < m; i++) {
		temp = (temp * i) % MOD;
		res = (res * temp) % MOD;
		res = (res * temp) % MOD;
	}
	temp = (temp * m) % MOD;
	temp = mu(temp, n - m + 1);
	res = (res * temp) % MOD;
	cout << res << '\n';
}
