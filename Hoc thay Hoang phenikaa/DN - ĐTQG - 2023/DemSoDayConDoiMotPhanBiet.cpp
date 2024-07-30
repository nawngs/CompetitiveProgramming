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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], it[6 * N + 3], lazy[6 * N + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

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

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(lnode, u, v), query(rnode, u, v));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, N);
	int r = 0;
	ll res = 0;
	for (int l = 1; l <= n; l++) {
		while (r < n) {
			r ++;
			if (query(1, 1, N, a[r], N) == 0) {
				r --;
				break;
			}
			update(1, 1, N, a[r], N, -1);
		}
		res += 1ll * (r - l + 1);
		update(1, 1, N, a[l], N, 1);
	}
	cout << res;
}
	