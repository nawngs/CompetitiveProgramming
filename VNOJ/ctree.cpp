// link: https://oj.vnoi.info/problem/ctree

#include <bits/stdc++.h>

using namespace std;

const int COLOR_NUM = 15;
int n, res[10005], ans = 1e9, dp[10005][COLOR_NUM + 5], color;
vector < int > adj[10005];

void dfs(int u, int e){
	for(int i = 1; i <= COLOR_NUM; i++) dp[u][i] = i;
	//cout << u << " " << e << '\n';
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		for(int i = 1; i <= COLOR_NUM; i++){
			int mina = 1e9;
			for(int j = 1; j <= COLOR_NUM; j++){
				if(j != i) mina = min(mina, dp[v][j]);
			}
			dp[u][i] += mina;
			//cout << u << " " << i << " " << dp[u][i] << '\n';
		}
	}
}

void trace(int u, int e, int color){
	for(auto v : adj[u]){
		if(v == e) continue;
		int mina = 1e9;
		int pos;
		for(int i = 1; i <= COLOR_NUM; i++){
			if(i != color && mina > dp[v][i]){
				mina = dp[v][i];
				pos = i;
			}
		}
		res[v] = pos;
		trace(v, u, pos);
	}
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u  >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= COLOR_NUM; i++){
		if(ans > dp[1][i]){
			ans = dp[1][i];
			color = i;
		}
	}
	cout << ans << '\n';
	res[1] = color;
	trace(1, 0, color);
	for(int i = 1; i <= n; i++) cout << res[i] << '\n';
}