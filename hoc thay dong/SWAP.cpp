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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3], k;

struct SegmentTree {
	int it[4 * NMAX + 3];
	void update_range(int node, int l, int r, int u, int v, int val) {
		if (v < l || r < u) return ;
		if (u <= l && r <= v) {
			it[node] += val;
			return ;
		}
		update_range(lnode, u, v, val); update_range(rnode, u, v, val);
	}
	void update_p(int node, int l, int r, int u, int v) {
		if (l == r) {
			a[l] = v;
			it[node] = l;
			return ;
		}
		if (u <= (l + r) / 2) update_p(lnode, u, v);
		else update_p(rnode, u, v);
		if (a[it[node * 2]] >= a[it[node * 2 + 1]]) it[node] = it[node * 2];
		else it[node] = it[node * 2 + 1];
	}
	int query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return -1;
		if (u <= l && r <= v) return it[node];
		int mid = (l + r) / 2;
		int lval = query(lnode, u, v), rval = query(rnode, u, v);
		if (lval == -1) return rval;
		if (rval == -1) return lval;
		if (a[lval] >= a[rval]) return lval;
		return rval;
	}
	int query_p(int node, int l, int r, int u) {
		if (l == r) return l + it[node];
		if (u <= (l + r) / 2) return it[node] + query_p(lnode, u);
		else return it[node] + query_p(rnode, u);
	}
} tree2, tree3;

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tree2.update_p(1, 1, n, i, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n, mid, posl, posr;
		while (l <= r) {
			mid = (l + r) / 2;
			if (tree3.query_p(1, 1, n, mid) >= i) {
				posl = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = 1, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (tree3.query_p(1, 1, n, mid) <= min(i + k, n)) {
				posr = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		int posa = tree2.query(1, 1, n, posl, posr);
		//cout << posa << '\n';
		k -= (tree3.query_p(1, 1, n, posa) - i);
		cout << a[posa] << " ";
		tree2.update_p(1, 1, n, posa, -INF);
		tree3.update_range(1, 1, n, 1, posa - 1, 1);
	}
}