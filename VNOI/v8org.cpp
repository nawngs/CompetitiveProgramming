// link:https://oj.vnoi.info/problem/v8org
#include <bits/stdc++.h>

using namespace std;

int k, n, a[10005], dp[10005], ans = 0;
vector < int > adj[10005];

void dfs(int u, int e){
	dp[u] = 1;
	for(auto v : adj[u]){
		if(v != e){
			dfs(v, u);
			dp[u] += dp[v];
		}
	}
	if(dp[u] >= k){
		ans ++;
		dp[u] = 0;
	}
}

int main(){
	cin >> k >> n;
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		adj[i].push_back(a[i]);
		adj[a[i]].push_back(i);
	}
	dfs(1, 0);
	cout << ans;
}

