#include <bits/stdc++.h>

#define int ll
#define name "candytn"
#define test "test"
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

ll n, m, it[400003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] += 1ll * val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return LINF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	while (m--) {
		ll oper, x, y; cin >> oper >> x >> y;
		if (oper == 1) update(1, 1, n, x, y);
		else {
			if (y > x) cout << query(1, 1, n, x, y) << '\n';
			else cout << min(query(1, 1, n, x, n), query(1, 1, n, 1, y)) << '\n';
		}
	}
}