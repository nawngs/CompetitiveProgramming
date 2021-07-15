#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, x, sum = 0, f[100005], ans = 1e18;
vector < pair < ll, ll > > adj[100005];

void dfs(ll u, ll e){
	f[u] = 0;
	vector < ll > max_f;
	for(auto v : adj[u]){
		if(v.fi == e) continue;
		dfs(v.fi, u);
		f[u] = max(f[u], f[v.fi] + v.se);
		max_f.push_back(f[v.fi] + v.se);
	}
	sort(max_f.begin(), max_f.end());
	ll new_sum = sum;
	for(int i = max_f.size() - 1; i >= max(0, (int)max_f.size() - 2); i --){
		new_sum -= max_f[i];
	}
	//cout << u << " " << new_sum << '\n';
	ans = min(ans, new_sum);
}

int main(){
	cin >> n >> x;
	for(int i = 1; i < n; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		sum += 2 * w;
	}
	//cout << sum << '\n';
	dfs(x, 0);
	cout << ans;
}