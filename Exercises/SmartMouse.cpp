#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "SmartMouse";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[200003];

vector < int > adj[200003];

void dfs(int u, int e) {
	vector < int > tam;
	tam.clear();
	tam.push_back(0);
	tam.push_back(0);
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		tam.push_back(dp[v] + 1);
	}
	sort(tam.begin(), tam.end(), greater < int >());
	dp[u] = tam[1];
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	int q;
	cin >> q;
	while (q--) {
		int start;
		cin >> start;
		memset(dp, 0, sizeof(dp));
		dfs(start, 0);
		int ans = 0;
		for (auto v : adj[start]) ans = max(ans, dp[v] + 1);
		cout << ans << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
