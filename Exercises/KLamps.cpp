#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < ll, ll >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "klamps";
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

ll n, it[800003], k, frac[200003];

pll a[100003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}


int main() {
	fast;
	fre();
	cin >> n >> k;
	frac[0] = 1;
	for (int i = 1; i <= 2 * n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	vector < ll > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		roi_rac.push_back(a[i].fi);
		roi_rac.push_back(a[i].se);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].fi) - roi_rac.begin();
		a[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].se) - roi_rac.begin();
		update(1, 0, 2 * n, a[i].fi, 1);
	}
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return x.se < y.se;
	});
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		update(1, 0, 2 * n, a[i].fi, -1);
		ll tam = query(1, 0, 2 * n, 0, a[i].se);
		if (tam >= k - 1) res = (res + Ckn(k - 1, tam)) % MOD;
	}
	cout << res;
}
