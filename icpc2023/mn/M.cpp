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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[NMAX + 3], b[NMAX + 3], f[NMAX + 3];

vector < int > compress;

struct BIT {
	int bit[2 * NMAX + 3], n, total = 0;
	void init(int _n) {
		n = _n; total = 0;
		for (int i = 1; i <= n; i++) bit[i] = 0;
	}
	void update(int u, int v) {
	    int idx = u;
	    total += v;
	    while (idx <= n) {
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
	int query(int p) {
		return total - get(p - 1);
	}
} tree;

void sol() {
	compress.clear();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		compress.pb(a[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		compress.pb(b[i]);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	for (int i = 1; i <= n; i++) 
		a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
	for (int i = 1; i <= m; i++) 
		b[i] = lower_bound(compress.begin(), compress.end(), b[i]) - compress.begin() + 1;
	sort(b + 1, b + m + 1);
	tree.init(n + m);
	ll res = 0;
	for (int i = 1; i <= n; i++) res += tree.query(a[i] + 1), tree.update(a[i], 1);
	for (int i = 1; i <= m; i++) f[i] = tree.get(b[i] - 1);
	tree.init(n + m);
	int cur = 0;
	for (int i = 1; i <= m; i++) {
		int pre = tree.query(b[i] + 1) + f[i] - tree.get(b[i] - 1);
		while (1) {
			if (cur == n) break;
			cur ++; tree.update(a[cur], 1);
			int temp = tree.query(b[i] + 1), temp2 = f[i] - tree.get(b[i] - 1);
			if (temp > temp2) {
				pre = min(pre, temp + temp2);
				if (pre < temp + temp2) tree.update(a[cur], -1), cur --;
				break;
			}
			pre = temp + temp2;	
		}
		//cout << cur << '\n';
		res += pre;
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}