#include <bits/stdc++.h>

#define name ""
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
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, l[N + 3], r[N + 3], a[N + 3];

vector < int > add[N + 3], del[N + 3];

ll it[6 * N + 3], lazy[6 * N + 3];

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return -LINF;
	if (u <= l && r <= v) return it[node];
	return max(query(lnode, u, v), query(rnode, u, v));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> a[i];
		add[l[i]].pb(i);
		del[r[i] + 1].pb(i);
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : add[i]) update(1, 0, n, 0, i - 1, a[x]);
		for (auto x : del[i]) update(1, 0, n, 0, l[x] - 1, -a[x]);
		ll temp = query(1, 0, n, 0, i - 1);
		// cout << temp << '\n';
		res = max(res, temp);
		update(1, 0, n, i, i, temp);
	}
	cout << res;
}