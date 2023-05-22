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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, f[300003], dp[300003];

pll a[300003];

vector < ll > it[300003], val[300003];

ll bs(ll pos, ll gt) {
	ll l = 0, r = val[pos].size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val[pos][mid] < gt) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void update(ll node, ll l, ll r, ll pos, ll val, ll lev) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[lev][node] += val;
		it[lev][node] %= MOD;
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val, lev);
	update(node * 2 + 1, mid + 1, r, pos, val, lev);
	it[lev][node] = it[lev][node * 2] + it[lev][node * 2 + 1];
}

ll query(ll node, ll l, ll r, ll u, ll v, ll lev) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[lev][node];
	ll mid = (l + r) / 2;
	return (query(node * 2, l, mid, u, v, lev) + query(node * 2 + 1, mid + 1, r, u, v, lev)) % MOD;
}

void sol() {
	cin >> n;
	f[0] = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		f[i] = INF;
	}
	sort(a + 1, a + n + 1, [](pll &x, pll &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
	});
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		ll l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid] < a[i].se) {
				ans = mid;
				l = mid + 1;
			}
			else  r = mid - 1;
		}
		dp[i] = ans + 1;
		res = max(res, ans + 1);
		val[dp[i]].push_back(a[i].se);
		f[ans + 1] = min(f[ans + 1], a[i].se);
	}
	for (int i = 1; i <= n; i++) {
		if (val[i].size() != 0) {
			sort(val[i].begin(), val[i].end());
			it[i].resize(val[i].size() * 6 + 5, 0);
		}
	}
	for (int i = 1; i <= n; i++) {
		ll cnt = 0, tam = 0;
		if (dp[i] == 1) cnt = 1; 
		else {
			tam = bs(dp[i] - 1, a[i].se);
			if (tam == -1) continue;
			cnt = query(1, 0, val[dp[i] - 1].size() - 1, 0, tam, dp[i] - 1);
		}
		ll temp = bs(dp[i], a[i].se) + 1;
		update(1, 0, val[dp[i]].size() - 1, temp, cnt, dp[i]);
	}
	cout << res << '\n' << it[res][1] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
