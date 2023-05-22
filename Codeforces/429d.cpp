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

ll n, ans = LINF;

pll a[100003];

ll dis(pll x, pll y) {
	return (x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se);
}

ll calc(int l, int r) {
	if (l == r) return INF;
	if (r - l == 1) 
		return min(ans, dis(a[l], a[r]));
	ll res = min(calc(l, (l + r) / 2), calc((l + r) / 2 + 1, r));
	sort(a + l, a + r + 1, [&](pll &x, pll &y) {
		return x.se < y.se;
	});
	vector < pll > tmp;
	int mid = (l + r) / 2;
	for (int i = l; i <= r; i++) {
		if ((a[i].fi - mid) * (a[i].fi - mid) < res) {
			for (int j = tmp.size() - 1; j >= 0; j--) res = min(res, dis(a[i], tmp[j]));
			tmp.push_back(a[i]);
		}
	}
	return res;
}	

main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = {i, a[i - 1].se + x};
	}
	cout << calc(1, n);
}
