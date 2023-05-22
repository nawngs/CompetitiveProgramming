#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int k;
vector<vector<int>> g;
vector<vector<int>> dp;

int dfs(int v, int p = -1){
	dp[v][0] = 1;
	int h = 0;
	for (int u : g[v]) if (u != p){
		int nh = dfs(u, v);
		vector<int> tmp(max(h, nh + 1) + 1);
		forn(i, h + 1) forn(j, nh + 1){
			if (i + j + 1 <= k)
				tmp[max(i, j + 1)] = add(tmp[max(i, j + 1)], mul(dp[v][i], dp[u][j]));
			if (i <= k && j <= k)
				tmp[i] = add(tmp[i], mul(dp[v][i], dp[u][j]));
		}
		h = max(h, nh + 1);
		forn(i, h + 1){
			dp[v][i] = tmp[i];
		}
	}
	return h;
}

int main() {

	int n;
	scanf("%d%d", &n, &k);
	g.resize(n);
	dp.resize(n, vector<int>(n, 0));
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	int ans = 0;
	forn(i, k + 1) ans = add(ans, dp[0][i]);
	printf("%d\n", ans);
	return 0;
}