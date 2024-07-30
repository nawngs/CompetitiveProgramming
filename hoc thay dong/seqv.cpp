#include <bits/stdc++.h>

#define name ""
#define int ll
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
const ll LINF = 1E17;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll rnd(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r) (rng);
}

int n, a[NMAX + 3], s[NMAX + 3];

vector < int > ms[NMAX + 3];

map < int, int > chg;

map < pll, int > f;

map < int, pll > XOR;

struct BIT {
	ll bit[NMAX + 3], n;
	void init(int _n) {
		n = _n;
		for (int i = 1; i <= _n; i++) bit[i] = 0;
	}
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
} tree;

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		if (a[i] < 0) {
			if (chg.find(a[i]) == chg.end()) chg[a[i]] = rnd(1, INF);
			a[i] = chg[a[i]];
		}
		if (XOR.find(a[i]) == XOR.end()) XOR[a[i]] = {rnd(1, LINF), rnd(1, LINF)};
	}
	f[{0, 0}] = 0;
	int res = 0;
	pll cur = {0, 0};
	for (int i = 1; i <= n; i++) {
		cur.fi ^= XOR[a[i]].fi; cur.se ^= XOR[a[i]].se;
		if (f.find(cur) != f.end()) {
			int pre = f[cur];
			swap(ms[i], ms[pre]);
			ms[i].pb(s[pre]);
		}
		f[cur] = i;
	}
	vector < int > compress;
	for (int i = 1; i <= n; i++) if (ms[i].size()) {
		compress.clear();
		compress.pb(-LINF);
		ms[i].pb(s[i]);
		for (auto x : ms[i]) compress.pb(x);
		sort(compress.begin(), compress.end());
		compress.erase(unique(compress.begin(), compress.end()), compress.end());
		tree.init(compress.size());
		for (auto x : ms[i]) {
			x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
			res += tree.get(x - 1);
			tree.update(x, 1);
		}
	}
	cout << res;
}
