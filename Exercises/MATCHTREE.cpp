#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, ll> D;
#define fi first
#define se second 
const int N = (int)15e5+5;
int n, M; vector<int> adj[N];
D dp[N][2];
void dfs(int u, int p = -1) {
	for (int &v : adj[u]) if (v != p)
		dfs(v, u);
	dp[u][0] = {0, 1}; dp[u][1] = {0, 0};
	vector<ll> mp, ms;
	vector<int> mt, ver; int s = 0;
	for (int &v : adj[u]) if (v != p) {
		int k = max(dp[v][0].fi, dp[v][1].fi); ll num = 0;
		for (int i = 0; i < 2; ++i)
			if (dp[v][i].fi == k) num += dp[v][i].se;
		dp[u][0].fi += k; dp[u][0].se *= num; dp[u][0].se %= M;
		mp.emplace_back(num); ms.emplace_back(num);	
		mt.emplace_back(k); s += k;
		ver.emplace_back(v);
	}
	
	for (int i = 1; i < int(mp.size()); ++i)
		mp[i] *= mp[i-1], mp[i] %= M;
	for (int i = (int)mp.size()-2; i >= 0; --i)
		ms[i] *= ms[i+1], ms[i] %= M;
		
	for (int i = 0; i < int(mp.size()); ++i) {
		int v = ver[i]; s -= mt[i]; s += dp[v][0].fi+1;
	
		ll num = (i>0?mp[i-1]:1)*(i<((int)mp.size()-1)?ms[i+1]:1)%M*dp[v][0].se%M;
		if (dp[u][1].fi < s) dp[u][1] = {s, num};
		else if (dp[u][1].fi == s) dp[u][1].se += num;
		dp[u][1].se %= M;
	
		s += mt[i]; s -= dp[v][0].fi+1;
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);	
	if (fopen("MATCHTREE.inp", "r"))
		freopen("MATCHTREE.inp", "r", stdin),
		freopen("MATCHTREE.out", "w", stdout);
	cin >> n;
	for (int i = 0, u, v; i < n-1; ++i)
		cin >> u >> v, u--, v--,
		adj[u].emplace_back(v),
		adj[v].emplace_back(u);
	cin >> M;
	dfs(0);
	int mt = max(dp[0][0].fi, dp[0][1].fi); ll num = 0;
	if (dp[0][0].fi == mt) num += dp[0][0].se;
	if (dp[0][1].fi == mt) num += dp[0][1].se;
	cout << mt << '\n' << num%M;
	return 0;
}