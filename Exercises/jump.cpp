#include <bits/stdc++.h>

using namespace std;

int n, a[1005], dp[1005], ans = 1;

vector < int > adj[1005];

int bs(int x){
	int l = 1, r = n, mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(a[mid] == x) return mid;
		if(a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
void dfs(int u){
	if(dp[u] != -1) return ;
	dp[u] = 1;
	for(auto v : adj[u]){
		//cout << u << " " << v << '\n';
		dfs(v);
		dp[u] = max(dp[u], dp[v] + 1);
	}
	//cout << u << " " << dp[u] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("JUMP.inp", "r", stdin);
	freopen("JUMP.out", "w", stdout);
	cin >> n;
	memset(dp, 255, sizeof(dp));
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int temp = bs(a[i] + a[j]);
			if(temp == -1) continue;
			adj[i].push_back(temp);
			adj[j].push_back(temp);
		}
	}
	for(int i = 1; i <= n; i++){
		dfs(i);
		//cout << a[i] << " " << dp[i] << '\n';
		ans = max(ans, dp[i]);
	}
	cout << ans;
}