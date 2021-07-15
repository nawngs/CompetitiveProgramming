//link: https://oj.vnoi.info/problem/stone1
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, dp[405];
vector < ll > adj[405];

void dfs(ll u, ll e){
	dp[u] = 1;
	vector < ll > dp_u;
	dp_u.clear();
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		dp_u.push_back(dp[v]);
		sort(dp_u.begin(), dp_u.end());
		ll temp = 0;
		for(int i = dp_u.size() - 1; i >= 0; i--){
			dp[u] = max(dp[u], dp_u[i] + ((long long)dp_u.size() - 1 - i));
		}
	}
	//cout << u << " " << dp[u] << '\n';
}

int main(){
	cin >> n;
	ll u, cnt;
	while(cin >> u >> cnt){
		for(int i = 1; i <= cnt; i++){
			ll v;
			cin >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	dfs(1, 0);
	cout << dp[1] << '\n';
}

