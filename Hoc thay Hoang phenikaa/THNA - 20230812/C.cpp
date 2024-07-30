//[UNFINISHED]
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

int n, m, lose[NMAX + 3], res[NMAX + 3], cnt[NMAX + 3];

pii a[NMAX + 3];

vector < pii > adj[NMAX + 3];

set < pii > ms;

void dfs(int u) {
	if (!ms.empty() && u != m + 1) {
		pii it = *ms.begin();
		res[it.se] ++;
	}
	for (auto v : adj[u]) {
		ms.erase(ms.find(mp(cnt[v.se], v.se)));
		cnt[v.se] -= u - v.fi;
		ms.insert(mp(cnt[v.se], v.se));
		dfs(v.fi);
		ms.erase(ms.find(mp(cnt[v.se], v.se)));
		cnt[v.se] += (u - v.fi);
		ms.insert(mp(cnt[v.se], v.se));
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	for (int i = 0; i < n; i++) lose[i] = m + 1;
	for (int i = m; i >= 1; i--) {
		adj[lose[a[i].fi]].pb({i, a[i].fi});
		lose[a[i].se] = i;
	}
	for (int i = 0; i < n; i++) ms.insert({0, i});
	dfs(m + 1);
	for (int i = 0; i < n; i++) cout << res[i] << " ";
}