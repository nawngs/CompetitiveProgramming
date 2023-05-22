//link: https://oj.vnoi.info/problem/mtree
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll MOD = 1000000007;
ll n, f[100005], g[100005];
vector < pair < ll, ll > > adj[100005];

void inc(ll &a, ll b){
	a = (a + b % MOD) % MOD;
}

void dfs(ll u, ll e){
	g[u] = 1;
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		dfs(v.fi, u);
		inc(f[u], f[v.fi]);
		inc(g[u], v.se * g[v.fi]);
	}
	ll sum = 0;
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		inc(sum, g[v.fi] * v.se);
	}
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		inc(sum, MOD * MOD - g[v.fi] * v.se);
		inc(f[u], ((g[v.fi] * sum) % MOD) * v.se);
	}
	inc(f[u], g[u] - 1);
	//cout << u << " " << g[u] << " " << f[u] << '\n'; 	
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(1, 0);
	cout << f[1];
}
