#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, color[100003];

pll res[100003];

vector < int > adj[100003];

map < int, int > dfs(int u, int e) {
	pll &ans = res[u];
	ans.fi = 1; ans.se = color[u];
	map < int, int > cur;
	cur[color[u]] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		map < int, int > temp = dfs(v, u);
		if (sz(temp) > sz(cur)) {
			swap(temp, cur);
			ans = res[v];
		}
		for (auto x : temp) {
			cur[x.fi] += x.se;
			if (cur[x.fi] > ans.fi) {
				ans.fi = cur[x.fi]; ans.se = 1ll * x.fi;
			}
			else if (cur[x.fi] == ans.fi) ans.se += 1ll * x.fi;
		}
	}
	return cur;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> color[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << res[i].se << " ";
}