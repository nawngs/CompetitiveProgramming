#include <bits/stdc++.h>

using namespace std;

int n, k, ans = 0, odd = 0;
vector < int > adj[100005];

void dfs(int u, int e, int cnt_edge){
	odd += u % 2;
	ans = max(ans, odd);
	if(cnt_edge == k){
		odd -= u % 2;
		return ;
	}
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u, cnt_edge + 1);
	}
	odd -= u % 2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("PATHODD.inp", "r", stdin);
	freopen("PATHODD.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	cout << ans;
}