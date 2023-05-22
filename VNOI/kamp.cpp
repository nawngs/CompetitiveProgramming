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

const string NAME = "kamp";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, dp[500002][3], cnt[500002], res[500003];

bool home[500003];

vector < pll > adj[500003];

void dfs(int u = 1, int e = 0) {
	cnt[u] = home[u];
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);
		cnt[u] += cnt[v.fi];
		if (cnt[v.fi] != 0) dp[u][0] += dp[v.fi][0] + 2 * v.se;
	}
	dp[u][1] = dp[u][2] = dp[u][0];
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		if (cnt[v.fi] != 0) {
			dp[u][2] = min(dp[u][2], dp[u][0] - dp[v.fi][0] + dp[v.fi][1] - v.se);
			if (dp[u][2] < dp[u][1]) swap(dp[u][1], dp[u][2]);
		}
	}
}

void dfs2(int u = 1, int e = 0) {
	res[u] = dp[u][1];
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		vector < ll > cur_u, cur_v;
		for (int i = 0; i < 3; i++) {
			cur_u.push_back(dp[u][i]);
			cur_v.push_back(dp[v.fi][i]);
		}
		cur_u.push_back(cnt[u]);
		cur_v.push_back(cnt[v.fi]);
		if (dp[u][1] == dp[u][0] - dp[v.fi][0] + dp[v.fi][1] - v.se) swap(dp[u][1], dp[u][2]);
		if (cnt[v.fi] != 0) {
			dp[u][0] = dp[u][0] - dp[v.fi][0] - 2 * v.se;
			dp[u][1] = dp[u][1] - dp[v.fi][0] - 2 * v.se;
			cnt[u] -= cnt[v.fi];
		}
		if (cnt[u] != 0) {
			cnt[v.fi] += cnt[u];
			dp[v.fi][0] += dp[u][0] + 2 * v.se;
			dp[v.fi][1] += dp[u][0] + 2 * v.se;
			dp[v.fi][2] += dp[u][0] + 2 * v.se;
			dp[v.fi][2] = min(dp[v.fi][2], dp[v.fi][0] - dp[u][0] + dp[u][1] - v.se);
			if (dp[v.fi][2] < dp[v.fi][1]) swap(dp[v.fi][1], dp[v.fi][2]);
		}
		dfs2(v.fi, u);
		for (int i = 0; i < 3; i++) {
			dp[u][i] = cur_u[i];
			dp[v.fi][i] = cur_v[i];
		}
		cnt[u] = cur_u[3];
		cnt[v.fi] = cur_v[3];
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		home[x] = 1;
	}
	dfs();
	dfs2();
	for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}
