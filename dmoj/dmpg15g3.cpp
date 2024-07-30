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

int n, lk, rk, lc, rc, sze[NMAX + 3], cnt0 = 0;

ll ans = 0;

bool used[NMAX + 3];

string s;

vector < int > adj[NMAX + 3];

vector < pii > all;

vector < vector < pii > > V;

int bit[NMAX + 3];

int get(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
	if (u == 0) {
		cnt0 += v;
		return ;
	}
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int dfs(int u, int e = 0) {
	sze[u] = 1;
	for (auto v : adj[u]) 
		if (v != e && !used[v]) sze[u] += dfs(v, u);
	return sze[u];
}

int get_centroid(int u, int sz, int e = 0) {
	for (auto v : adj[u]) if (v != e && !used[v]) 
		if (sze[v] * 2 > sz) return get_centroid(v, sz, u);
	return u;
}

ll calc(const vector < pii > &x, int maxr, int maxc) {
	if (maxr < 0 || maxc < 0) return 0;
	ll res = 0;
	int j = 0;
	for (int i = SZE(x) - 1; i >= 0; i--) {
		while (j < SZE(x) && x[i].fi + x[j].fi <= maxr) update(x[j ++].se, 1);
		res += get(maxc - x[i].se) + cnt0 * (maxc >= x[i].se);
		if (j >= i && x[i].fi * 2 <= maxr && x[i].se * 2 <= maxc) res --;
		//if (maxr == 3 && maxc == 0) cout << "HAHA " << i << " " << res << '\n';
	}
	for (int i = 0; i < j; i++) update(x[i].se, -1);
	return res / 2;
}

ll solve(vector < pii > &x) {
	sort(x.begin(), x.end());
	return calc(x, rk, rc) - calc(x, rk, lc - 1) - calc(x, lk - 1, rc) + calc(x, lk - 1, lc - 1);
}

void dfs2(int u, int e, int curk, int curc) {
	if (s[u] == 'K') curk ++;
	else curc ++;
	if ((lk <= curk && curk <= rk) && (lc <= curc && curc <= rc)) ans ++;
	all.pb(mp(curk, curc)); V.back().pb(mp(curk, curc));
	for (auto v : adj[u]) if (v != e && !used[v]) 
		dfs2(v, u, curk, curc);
}

void centroid(int u = 1) {
	int C = get_centroid(u, dfs(u)); used[C] = 1;
	if ((s[C] == 'K' && lk <= 1 && lc == 0) || (s[C] == 'C' && lk == 0 && lc <= 1)) ans ++;
	if ((s[C] == 'K' && rk == 0) || (s[C] == 'C' && rc == 0)) {
		for (auto v : adj[C]) 
			if (!used[v]) centroid(v);
		return ;
	}
	if (s[C] == 'K') lk --, rk --;
	else lc --, rc --;
	vector < pii >().swap(all); vector < vector < pii > >().swap(V);
	for (auto v : adj[C]) if (!used[v]) {
		V.pb(vector < pii > ());
		dfs2(v, C, 0, 0);
	}
	ans += solve(all);
	for (auto &x : V) ans -= solve(x);
	if (s[C] == 'K') lk ++, rk ++;
	else lc ++, rc ++;
	//cout << C << " " << ans << '\n';
	//return ;
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> lk >> rk >> lc >> rc >> s; s = ' ' + s;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	centroid();
	cout << ans;
}