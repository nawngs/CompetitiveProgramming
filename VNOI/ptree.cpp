//link: https://oj.vnoi.info/problem/ptree

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const long long INF = 1E18;
ll n, p, c[205], dp[205][205], trace[205][205], last[205];
vector < ll > adj[205];

void dfs(ll u, ll e){
	//for(int i = 1; i <= p; i++) dp[u][i] = -INF;
	//dp[u][0] = 0;
	//dp[u][1] = c[u];
	last[u] = e;
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		for(int i = p; i >= 1; i--){
			for(int j = i - 1; j >= 1; j--){
				//dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
				if(dp[u][i] < dp[u][i - j] + dp[v][j]){
					dp[u][i] = dp[u][i - j] + dp[v][j];
					trace[v][i] = j;
				}
			}
		}
	}
}

void truy_vet(ll u, ll e){
	for(int i = adj[u].size() - 1; i >= 0; i--){
		ll v = adj[u][i];	
		if(v == last[u]) continue;
		if(trace[v][e] > 0){
			truy_vet(v, trace[v][e]);
			e -= trace[v][e];
		}
	}
	cout << u << " ";
}


int main(){
	cin >> n >> p;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i < n; i++){
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		dp[i][1] = c[i];
		for(int j = 2; j <= p; j++){
			dp[i][j] = -INF;
		}

	}
	dfs(1, 0);
	ll ans = -INF;
	ll vt = 0;
	for(int i = 1; i <= n; i++){
		if(dp[i][p] > ans){
			ans = dp[i][p];
			vt = i;
		}
		//cout << dp[i][p] << '\n';
	}
	//if(ans == 629) cout << ans << '\n';
	//cout << trace[2][p].fi << " " << trace[2][p].se << '\n';
	truy_vet(vt, p);

}

