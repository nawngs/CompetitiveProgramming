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
const int NMAX = 1E4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int SIZE = 500;

struct BIT {
	int bit[NMAX + 3];
	BIT() {
		for (int i = 0; i <= NMAX; i++) bit[i] = 0;
	}
	void update(int u, int v) {
	    int idx = u;
	    while (idx <= NMAX) {
	        bit[idx] += v;
	        idx += (idx & (-idx));
	    }
	}
	int get(int p) {
	    int idx = p, ans = 0;
	    while (idx > 0) {
	        ans += bit[idx];
	        idx -= (idx & (-idx));
	    }
	    return ans;
	}
} tree[SIZE + 3];

int a[3 * NMAX + 3], n;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] = NMAX - a[i] + 1;
		tree[i / SIZE].update(a[i], 1);
	}
	int q; cin >> q;
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, x; cin >> l >> r >> x; x = NMAX - x + 1; 
			int lblock = l / SIZE, rblock = r / SIZE;
			int res = 0;
			for (int id = lblock + 1; id < rblock; id++) res += tree[id].get(x - 1);
			for (int i = l; i <= min(r, (lblock + 1) * SIZE - 1); i++) res += (a[i] < x);
			if (lblock != rblock) for (int i = rblock * SIZE; i <= r; i++) res += (a[i] < x);
			cout << res << '\n';
		}
		else {
			int i, x; cin >> i >> x; x = NMAX - x + 1;
			int id = i / SIZE;
			tree[id].update(a[i], -1);
			tree[id].update(x, 1);
			a[i] = x;
		}
	}
	
}