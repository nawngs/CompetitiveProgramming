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

const string NAME = "tree-edge-color-queries";
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

int n, dp[300003];


pair < pii, int > a[300003];

vector < pii > adj[300003];

map < int, int > cnt[300003];

bool dfs(int u, int e, int pre) {
	bool th = 1;
	vector < int > tam;
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		if (v.se == pre) th = 0;
		int tem = dfs(v.fi, u, v.se);
		dp[u] += dp[v.fi];
		if (!tem) dp[u] --;
		tam.push_back(v.se);
	}
	sort(tam.begin(), tam.end());
	if (tam.size()) {
		int dem = 1;
		for (int i = 1; i < tam.size(); i++) if (tam[i] != tam[i - 1]) dem ++;
		dp[u] += dem;
	}
	//cout << u << " " << dp[u] << '\n';
	return th;
}


int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		a[i] = {{u, v}, c};
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
		cnt[u][c] ++;
		cnt[v][c] ++;
	}
	dfs(1, 0, -1);
	cout << dp[1] << " ";
	int q;
	cin >> q;
	while (q--) {
		int i, x;
		cin >> i >> x;
		int u = a[i].fi.fi;
		int v = a[i].fi.se;
		cnt[u][a[i].se] --;
		cnt[v][a[i].se] --;
		if (cnt[u][a[i].se] == 0 && cnt[v][a[i].se] == 0) dp[1] --;
		if (cnt[u][a[i].se] >= 1 && cnt[v][a[i].se] >= 1) dp[1] ++;
		if (cnt[v][x] == 0 && cnt[u][x] == 0) dp[1] ++;
		if (cnt[v][x] >= 1 && cnt[u][x] >= 1) dp[1] --;
		cnt[v][x] ++;
		cnt[u][x] ++;
		a[i].se = x;
		cout << dp[1] << " ";
	}
	
}