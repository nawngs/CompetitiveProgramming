#include <bits/stdc++.h>

#define name "countpath"
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
const int NMAX = 5e5;
const ll MOD = 998244353;
const ll BASE = 2309;

struct Edge {
	int st, fn, b, l, id;
	Edge() {
		id = st = fn = b = l = 0;
	}
} a[NMAX + 3];

int n, m, bit[NMAX + 3], pos[NMAX + 3], f[NMAX + 3];

map < int, vector < int > > id;

void update(int u, int val) {
	while (u <= m) {
		bit[u] = (bit[u] + val) % MOD;
		u += (u & (-u));
	}
}

int get(int u) {
	int res = 0;
	while (u > 0) {
		res = (res + bit[u]) % MOD;
		u -= (u & (-u));
	}
	return res;
}

int query(int l, int r) {
	if (l > r) return 0;
	return (get(r) - get(l - 1) + MOD) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].st >> a[i].fn >> a[i].b >> a[i].l;
		a[i].id = i;
	}
	sort(a + 1, a + m + 1, [&](Edge &x, Edge &y) {
		if (x.fn != y.fn) return x.fn < y.fn;
		return x.l < y.l;
	});
	for (int i = 1; i <= m; i++) {
		pos[a[i].id] = i;
		if (a[i].fn != a[i - 1].fn) f[a[i].fn] = i;
		id[a[i].b].pb(i);
	}
	ll res = 0;
	for (auto x : id) {
		vector < pii > temp;
		for (auto i : x.se) {
			int cur = 1;
			if (f[a[i].st] != 0) {
				int l = f[a[i].st], r = m, mid, ans = l - 1;
				while (l <= r) {
					mid = (l + r) / 2;
					if (a[mid].fn > a[i].st) {
						r = mid - 1;
						continue;
					}
					if (a[mid].l < a[i].l) {
						ans = mid;
						l = mid + 1;
					}
					else r = mid - 1;
				}
				cur = (cur + query(f[a[i].st], ans)) % MOD;
			}
			temp.pb({i, cur});
			res = (res + cur) % MOD;
		}
		for (auto i : temp) update(i.fi, i.se);
	}
	cout << res;
}