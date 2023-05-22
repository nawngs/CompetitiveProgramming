#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, low[NMAX + 3], high[NMAX + 3], res[NMAX + 3], it[4 * NMAX + 3];

pii Query[NMAX + 3];

vector < int > pos[NMAX + 3], id[NMAX + 3];

#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	update(lnode, pos); update(rnode, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pos[x].push_back(i);
	}
	for (int i = 1; i <= q; i++) {
		cin >> Query[i].fi >> Query[i].se;
		low[i] = 1, high[i] = n, res[i] = 1;
	}
	while (1) {
		bool unchaged = true;
		for (int i = 1; i <= q; i++) {
			if (low[i] > high[i]) continue;
			id[(low[i] + high[i]) / 2].pb(i);
		}
		memset(it, 0, sizeof(it));
		for (int i = NMAX; i >= 0; i--) {
			for (auto x : pos[i]) update(1, 1, n, x);
			while (sz(id[i])) {
				int index = id[i].back(); id[i].pop_back();
				unchaged = false;
				int val = query(1, 1, n, Query[index].fi, Query[index].se);
				if (val >= i) {
					res[index] = i;
					low[index] = i + 1;
				}
				else high[index] = i - 1;
			}
		}
		if (unchaged) break;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}