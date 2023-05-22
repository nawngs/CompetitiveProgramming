#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace	 std;

const string NAME = "colors";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll int unsigned n, c;

int main() {
	fast;
	int O; cin >> O;
	cin >> n >> c;	
	for (int i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
	}
	ll int unsigned res = c % MOD;
	for (int i = 2; i <= n; i++) res = (res * (c - 1)) % MOD;
	cout << res;
}
