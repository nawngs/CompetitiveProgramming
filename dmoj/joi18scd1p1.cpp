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

int n, a[NMAX + 3], sz[NMAX + 3], chainID[NMAX + 3], chainH[NMAX + 3], nchain = 1, h[NMAX + 3], par[NMAX + 3];

vector < int > adj[NMAX + 3];

deque < pii > values[NMAX + 3];

pii edges[NMAX + 3];

int bit[NMAX + 3];

int getSum(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int dfs(int u = 1, int e = 0) {
	sz[u] = 1; h[u] = h[e] + 1;
	for (auto v : adj[u]) {
		par[v] = u;
		sz[u] += dfs(v, u);
	}
	return sz[u];
}

void hld(int u) {
	chainID[u] = nchain;
	if (!chainH[nchain]) chainH[nchain] = u;
	int big = -1;
	for (auto v : adj[u]) if (big == -1 || sz[v] > sz[big]) big = v;
	if (big != -1) hld(big);
	for (auto v : adj[u]) if (v != big) nchain ++, hld(v);
}

int calc(int u) {
	vector < pii > arrv, temp;
	int id = chainID[u], ance;
	while (u) {
		ance = chainH[id];
		int sze = h[u] - h[ance] + 1;
		temp.clear();
		for (int i = 0; i < SZE(values[ance]); i++) {
			if (sze > values[ance][i].se) {
				sze -= values[ance][i].se;
				temp.pb(values[ance][i]);
			}
			else {
				temp.pb(mp(values[ance][i].fi, sze));
				break;
			}
		}
		while (!temp.empty()) {
			arrv.pb(temp.back());
			temp.pop_back();
		}
		u = par[ance], id = chainID[u];
	}
	for (int i = 1; i <= n; i++) bit[i] = 0;
	ll res = 0;
	for (auto x : arrv) {
		res += 1ll * x.se * getSum(x.fi - 1);
		update(x.fi, x.se);
	}
	return res;
}

void add(int u) {
	int id = chainID[u], ance;
	int color = a[u];
	while (u) {
		ance = chainH[id];
		int sze = h[u] - h[ance] + 1;
		while (!values[ance].empty()) {
			if (sze >= values[ance].front().se) {
				sze -= values[ance].front().se;
				values[ance].pop_front();
			}
			else {
				values[ance].front().se -= sze;
				break;
			}
		}
		values[ance].push_front({color, h[u] - h[ance] + 1});
		u = par[ance], id = chainID[u];
		// cout << ance << '\n';
		// for (auto x : values[ance]) cout << x.fi << " " << x.se << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	
	vector < int > rr;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		rr.pb(a[i]);
	}
	
	sort(rr.begin(), rr.end()); rr.erase(unique(rr.begin(), rr.end()), rr.end());
	for (int i = 1; i <= n; i++) 
		a[i] = lower_bound(rr.begin(), rr.end(), a[i]) - rr.begin() + 1;
	
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		edges[i] = mp(u, v);
	}
	
	dfs(); hld(1);
	
	for (int i = 1; i < n; i++) {
		int u = edges[i].fi, v = edges[i].se;
		cout << calc(u) << '\n';
		add(v);
	}
}