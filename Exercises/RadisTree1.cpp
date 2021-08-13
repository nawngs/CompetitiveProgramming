//tree algo
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int n, res[100005], f[100005];
vector < int > adj[100005];

void dfs(int u, int e){
	f[u] = 0;
	res[u] = 0;
	//int max_f = 0;
	vector < int > max_f;
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		f[u] = max(f[u], f[v] + 1);
		res[u] = max(res[u], f[u]);
		res[u] = max(res[u], res[v]);
		max_f.push_back(f[v]);
	}
	sort(max_f.begin(), max_f.end());
	if(max_f.size() >= 2) res[u] = max(res[u], max_f[max_f.size() - 1] + max_f[max_f.size() - 2] + 2);
	//2cout << u << " " << f[u] << " " << res[u] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("RadisTree1.inp", "r", stdin);
	freopen("RadisTree1.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << res[1] << '\n';
}