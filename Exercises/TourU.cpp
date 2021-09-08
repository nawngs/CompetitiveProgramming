#include <bits/stdc++.h>
#define ll long long
#define pll pair < long long , long long > 
#define fi first
#define se second 

using namespace std;

ll n, cnt[100005], d[100005], ans, sum = 0, f[100005], s, k;

bool check[100005];

vector < pll > adj[100005];

void dfs1(ll u, ll e){
	cnt[u] = check[u];
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		dfs1(v.fi, u);
		if(cnt[v.fi] != 0){
			sum += v.se;
			//cout << v.fi << " " << v.se << '\n';
		}
		cnt[u] += cnt[v.fi];
	}
	//cout << sum << '\n';
	//cout << u << " " << cnt[u] << '\n';
}

void dfs(ll u, ll e){
	vector < ll > max_f;
	f[u] = 0;
	for(auto v : adj[u]){
		if(v.fi == e || cnt[v.fi] == 0) continue;
		dfs(v.fi, u);
		f[u] = max(f[u], f[v.fi] + v.se);
		max_f.push_back(f[v.fi] + v.se);
	}
	ans = min(ans, sum - f[u]);	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("TourU.inp", "r", stdin);
	freopen("TourU.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	cin >> s >> k;
	for(int i = 1; i <= k; i++){
		ll x;
		cin >> x;
		sum += d[x];
		check[x] = true;
	}
	//dfs2(s, 0);
	dfs1(s, 0);
	sum *= 2;
	dfs(s, 0);
	cout << sum - f[s];
}
