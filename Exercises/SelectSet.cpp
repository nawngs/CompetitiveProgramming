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

const string NAME = "selectset";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[100003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		a[x % m] ++;
	}
	ll res = 0;
	if (a[0] != 0) res ++;
	for (int i = 1; i <= m / 2; i++) {
		if (i + i == m) res += (a[i] != 0);
		else res += max(a[i], a[m - i]);
	}
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
