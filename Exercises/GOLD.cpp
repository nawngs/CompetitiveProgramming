#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, g[100005], f[100005], n;

vector < ll > adj[100005], a;

void dfs(ll u, ll e){
	f[u] = a[u];
	g[u] = 0;
	//ll sumf = 0;
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		g[u] += max(f[v], g[v]);
		f[u] += g[v];
	}
	//cout << u << " " << g[u] << " " << f[u] << '\n';
	if(e == 0) cout << max(g[u], f[u]) << '\n';
}

void input(){
	cin >> n;
	a.clear();
	a.push_back(0);
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		g[i] = f[i] = 0;
	}
	for(int i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	dfs(1, 0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("GOLD.inp", "r", stdin);
	freopen("GOLD.out", "w", stdout);
	cin >> t;
	while(t --){
		input();
	}
}