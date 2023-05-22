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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, t;

ll nhanan(ll a, ll b, ll m) {
	if (b == 0) return 0;
	ll x = nhanan(a, b / 2, m);
	x = (x + x) % MOD;
	if (b % 2 == 1) x = (x + a) % MOD;
	return x;
}

ll mu(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, m);
	x = nhanan(x, x, m);
	if (b % 2 == 1) x = nhanan(x, a, m);
	return x;
}

void sol() {
	cin >> n >> k >> t;
	ll tam = mu(k, n, MOD - 1);
	cout << mu(t, tam, MOD);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
