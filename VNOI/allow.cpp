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

ll n, c;

pll a[23];

int main() {
	fast;
	cin >> n >> c;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		if (a[i].fi >= c) {
			res += a[i].se;
			a[i].se = 0;
		}
	}
	sort(a + 1, a + n + 1);
	while (1) {
		ll val = c;
		for (int i = n; i >= 1; i--) {
			ll temp = min(val / a[i].fi, a[i].se);
			val -= temp * a[i].fi;
			a[i].se -= temp;
		}
		for (int i = 1; i <= n; i++) {
			ll temp = min((val + a[i].fi - 1) / a[i].fi, a[i].se);
			val -= temp * a[i].fi;
			a[i].se -= temp;
			if (val <= 0) break;
		}
		if (val > 0) break;
		res ++;
	}
	cout << res;
}
