//[FINISHED]
#include <bits/stdc++.h>

#define name "sum-min-gcd"
#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 19972207;
const ll LINF = 1E18;
const int NMAX = 25e4;
const ll MOD = 1e9 + 19972207;
const ll BASE = 2309;

ll n, a[NMAX + 3], it[6 * NMAX + 3], lazy[6 * NMAX + 3];

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] = (lazy[node] * (r - l + 1)) % MOD;
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = (it[node * 2] + it[node * 2 + 1]) % MOD;
}

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return (query(lnode, u, v) + query(rnode, u, v)) % MOD;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st; a[0] = -LINF; st.push(0);
	vector < pll > div, nxtdiv;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] > a[i]) st.pop();
		update(1, 1, n, st.top() + 1, i, a[i] % MOD);
		st.push(i);
		nxtdiv.clear();
		for (auto x : div) 
			nxtdiv.pb(mp(__gcd(x.fi, a[i]), x.se));
		nxtdiv.pb(mp(a[i], i));
		div.clear();
		for (auto x : nxtdiv) if (div.empty() || div.back().fi != x.fi) div.pb(x);
		// cout << i << '\n';
		// for (auto x : div) cout << x.fi << " " << x.se << ' ';
		// cout << '\n';
		int r = i;
		for (int j = SZE(div) - 1; j >= 0; j--) {
			res = (res + query(1, 1, n, div[j].se, r) * (div[j].fi % MOD)) % MOD;
			r = div[j].se - 1;
		}
	}
	cout << res;
}