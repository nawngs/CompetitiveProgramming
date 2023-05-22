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

ll n, m;

pll operator * (pll x, pll y) {
	pll res;
	res.fi = x.fi * y.fi;
	res.se = x.se * y.se;
	ll tam = __gcd(res.fi, res.se);
	res.fi /= tam;
	res.se /= tam;
	return res;
}

pll operator + (pll x, pll y) {
	pll res;
	res.fi = x.fi * y.se + y.fi * x.se;
	res.se = x.se * y.se;
	ll tam = __gcd(res.fi, res.se);
	res.fi /= tam;
	res.se /= tam;
	return res;
}

int main() {
	fast;
	cin >> m >> n;
	pll ans = {0, 1};
	for (int i = 1; i <= m + 1; i++) {
		pll tam = {5 * (i % 2 == 1 ? -1 : 1) * i * n, m + n - i + 1};
		for (int j = 1; j < i; j++) {
			pll temp = {m - j + 1, m + n - j + 1};
			tam = tam * temp;
		}
		ans = ans + tam;
	}	
	if (ans.se < 0) cout << -ans.fi << "/" << -ans.se << '\n';
	else cout << ans.fi << "/" << ans.se << '\n';
}

