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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, lazy1[6 * NMAX + 3], lazy2[6 * NMAX + 3];

void update(int node, int l, int r, int u, int v, ll a, ll b) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy1[node] += a - b * u;
		lazy2[node] += b;
		return ;
	}
	update(lnode, u, v, a, b); update(rnode, u, v, a, b);
}

ll query(int node, int l, int r, int u) {
	ll res = lazy1[node] + lazy2[node] * u;
	if (l == r) return res;
	if (u <= (l + r) / 2) return res + query(lnode, u);
	else return res + query(rnode, u);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			ll l, r, a, d; cin >> l >> r >> a >> d;
			update(1, 1, n, l, r, a, d);
		}
		else {
			int x; cin >> x;
			cout << query(1, 1, n, x) << '\n';
		}
	}
}