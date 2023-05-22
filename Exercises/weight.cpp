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

const string NAME = "WEIGHT";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[400003], l_min[400003], l_max[400003], val[400003];

pii it[2400003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].fi = max(it[node].fi, val);
		it[node].se = min(it[node].se, val);
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node].fi = max(it[node * 2].fi, it[node * 2 + 1].fi);
	it[node].se = min(it[node * 2].se, it[node * 2 + 1].se);
}

pii query(ll node, ll l, ll r, ll u, ll v) {
	if (r < u || v < l) return {0, n + 1};
	if (u <= l && r <= v) return it[node];
	pii lnode = query(node * 2, l, (l + r) / 2, u, v);
	pii rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	return {max(lnode.fi, rnode.fi), min(lnode.se, rnode.se)};
}

void roi_rac() {
	vector < pii > f;
	for (int i = 1; i <= n; ++i) f.push_back({a[i], i});
	sort(f.begin(), f.end());
	int dem = 1;
	for (int i = 0; i < f.size(); ++i) {
		dem += (i > 0 && f[i].fi != f[i - 1].fi);
		val[dem] = a[f[i].se];
		a[f[i].se] = dem;
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	roi_rac();
	for (int i = 1; i <= 4 * n; ++i) it[i] = {0, n + 1};
	for (int i = 1; i <= n; ++i) {
		pii tam1 = query(1, 1, n, a[i], n);
		pii tam2 = query(1, 1, n, 1, a[i]);
		l_max[i] = i - tam1.fi;
		l_min[i] = i - tam2.fi;
		update(1, 1, n, a[i], i);
 	}
	for (int i = 1; i <= 4 * n; ++i) it[i] = {0, n + 1};
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		pii tam1 = query(1, 1, n, a[i] + 1, n);
		pii tam2 = query(1, 1, n, 1, a[i] - 1);
		ll tamf = 1ll * l_max[i] * 1ll * (tam1.se - i);
		ll tamg = 1ll * l_min[i] * 1ll * (tam2.se - i);
		ans += (tamf - tamg) * 1ll * val[a[i]];
		update(1, 1, n, a[i], i);
	}
	cout << ans % MOD;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
