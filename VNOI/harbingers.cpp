#include <bits/stdc++.h>

#define int ll
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

using Line = pii;

int n, dp[100003], dis[100003];

pii a[100003];

vector < pii > adj[100003];

Line lines[100003];

stack < pair < int, Line > > st; // old top, old line

int top = 0;

int get(Line a, int x) {
	return a.fi * x + a.se;
}

bool bad(Line a, Line b, Line c) {
	return (double)(a.se - b.se) / (a.fi - b.fi) <= (double)(a.se - c.se) / (a.fi - c.fi);
	//return (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi) >= 0;
}

void Insert(Line newline) {
	int l = 1, r = top - 1, k = top, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (bad(lines[mid - 1], lines[mid], newline)) {
			k = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	st.push({top, lines[k]});
	top = k + 1; lines[k] = newline;
}

int query(int x) {
	int l = 0, r = top - 1, mid, ans = get(lines[l], x);
	while (l < r) {
		mid = (l + r) / 2;
		int v1 = get(lines[mid], x), v2 = get(lines[mid + 1], x);
		if (v1 > v2) l = mid + 1; 
		else r = mid;
		ans = min(ans, min(v1, v2));
	}
	return ans;
}

void Remove() {
	lines[top - 1] = st.top().se; top = st.top().fi;
	st.pop();
}

void dfs(int u, int e) {
	if (u != 1) dp[u] = query(a[u].se) + dis[u] * a[u].se + a[u].fi;
	Insert({-dis[u], dp[u]});
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dis[v.fi] = dis[u] + v.se;
		dfs(v.fi, u);
	}
	Remove();
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); adj[v].pb({u, c});
	}
	for (int i = 2; i <= n; i++) 
		cin >> a[i].fi >> a[i].se;
	dfs(1, 0);
	for (int i = 2; i <= n; i++) cout << dp[i] << " ";
}