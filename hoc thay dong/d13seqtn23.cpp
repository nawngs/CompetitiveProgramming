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

ll n, q, a[NMAX + 3];

struct BIT {
	ll bit[NMAX + 3], n;
	void update(int u, ll v) {
	    ll idx = u;
	    while (idx <= n) {
	        bit[idx] += v;
	        idx += (idx & (-idx));
	    }
	}
	ll get(int u) {
	    ll idx = u, ans = 0;
	    while (idx > 0) {
	        ans += bit[idx];
	        idx -= (idx & (-idx));
	    }
	    return ans;
	}
} tree1, tree2;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> q;
	tree1.n = tree2.n = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tree1.update(i, a[i]);
		if (i & 1) tree2.update(i, a[i]);
	}
	while (q--) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			tree1.update(x, y - a[x]);
			if (x & 1) tree2.update(x, y - a[x]);
			a[x] = y;
		}
		else {
			ll res = tree1.get(y) - tree1.get(x - 1);
			int val = 1;
			while (1) {
				int u = (x + val - 1) / val, v = y / val;
				if (u > v) break;
				res += tree2.get(v) - tree2.get(u - 1);
				val *= 2;
			}
			cout << res << '\n';
		}
	}
}