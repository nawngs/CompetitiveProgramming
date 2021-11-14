#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "Colpaths";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, a[300005];
ll dp[300005][35];

vector < int > adj[300005];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

ll dfs(int u, int mask) {
	if (dp[u][mask] != -1) return dp[u][mask];
	if (!getbit(mask, a[u])) return (dp[u][mask] = 0);
	ll res = 0;
	for (auto v : adj[u]) if (getbit(mask, a[v])) res += dfs(v, mask - (1 << a[u]));
	return (dp[u][mask] = res);
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] --;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[i][(1 << a[i])] = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int mask = 0; mask <= (1 << k) - 1; mask ++) {
			ans += dfs(i, mask);
		}
	
	cout << ans - n;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
