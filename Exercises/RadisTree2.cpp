#include <bits/stdc++.h>
#define pii pair < int, int > 
#define fi first
#define se second

using namespace std;

int n, tam_w = -1e6 - 7;

long long ans = -1e18, dp[100005], f[100005];

vector < pii > adj[100005];

void dfs(int u, int e){
	//cout << u << '\n';
	dp[u] = f[u] = -1e18;
	vector < long long > max_f;
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		//cout << v.fi << '\n';
		dfs(v.fi, u);
		dp[u] = max(dp[u], dp[v.fi]);
		//if(u == 1) cout << f[v.fi] + v.se << '\n';
		max_f.push_back(f[v.fi] + v.se);
	}
	sort(max_f.begin(),max_f.end());
	if(!max_f.size()) dp[u] = f[u] = 0;
	if(max_f.size() >= 2) dp[u] = max(dp[u], max_f[max_f.size() - 1] + max_f[max_f.size() - 2]);
	if(max_f.size() >= 1){
		dp[u] = max(dp[u], max_f[max_f.size() - 1]);
		f[u] = max_f[max_f.size() - 1];
		f[u] = max(f[u], (long long) 0);
	}
	//cout << u << " " << f[u] << '\n';

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("RadisTree2.inp", "r", stdin);
	freopen("RadisTree2.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		tam_w = max(tam_w, w);
	}
	dfs(1, 0);
	if(dp[1] == 0) cout << tam_w;
	else cout << dp[1] << '\n';
}