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

const string NAME = "bonus";
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

ll n, k, r, p, s[503][503];

pii a[5];

pair < pii, pii > get(pair < pii, pii > x, pair < pii, pii > y) {
	pair < pii, pii > ans;
	ans.fi.fi = max(x.fi.fi, y.fi.fi);
	ans.se.fi = min(x.se.fi, y.se.fi);
	ans.fi.se = max(x.fi.se, y.fi.se);
	ans.se.se = min(x.se.se, y.se.se);
	return ans;
}

ll get(pair < pii, pii > x) {
	if (x.fi.fi > x.se.fi || x.fi.se > x.se.se) return 0;
	return s[x.se.fi][x.se.se] - s[x.fi.fi - 1][x.se.se] - s[x.se.fi][x.fi.se - 1] + s[x.fi.fi - 1][x.fi.se - 1];
}

int main() {
	fast;
	fre();
	cin >> n >> k >> r >> p;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	}
	ll res = 0;
	while (k--) {
		for (int i = 0; i < p; i++) 
			cin >> a[i].fi >> a[i].se;
		ll cur = 0;
		for (int bit = 1; bit < (1 << p); bit++) {
			pair < pii, pii > inter;
			inter = {{1, 1}, {n, n}};
			for (int i = 0; i < p; i++) {
				if (!(bit >> i & 1)) continue;
				inter = get(inter, {{a[i].fi, a[i].se}, {a[i].fi + r - 1, a[i].se + r - 1}});
			}
			if (__builtin_popcount(bit) & 1) cur += get(inter);
			else cur -= get(inter);
		}
		res = max(res, cur);
	}
	cout << res;
}
