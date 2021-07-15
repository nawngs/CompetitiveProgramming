//link: https://vnoi-admin.github.io/statements/FC/FCB032/count.pdf
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, f[200003], res[200003], a[200003], pos[200003];
vector < ll > adj[200003], check[200003];

void dfs(ll u, ll e){
	f[u] = 1;
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
	}
	if(pos[a[u]] != -1) f[pos[a[u]]] --;
	check[u].push_back(a[u]);
	pos[a[u]] = u;
	//bool th = true;	
	for(auto v : adj[u]){
		if(v == e) continue;
		//cout << u << " " << v << " " << f[v] << " " << pos[1] << '\n';	
		f[u] += f[v];
	}
	res[u] = f[u];
	for(auto v : check[u]){
		pos[v] = e;
		check[e].push_back(v);
	}


}	

int main(){
	cin >> n;
	memset(pos, 255, sizeof(pos));
	for(int i = 1; i < n; i++){
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << res[i] << ' ';
}