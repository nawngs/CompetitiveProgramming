#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9 + 7;

int n, t, a[100005], f[100005], ans;

vector < int > adj[100005];

int bs(int x){
	int l = 1, r = n, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2; 
	//	cout << mid << " " << f[mid] << " " << x << '\n';
		if(f[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void dfs(int u, int e){
	int temp = bs(a[u]);
	int pref = f[temp + 1];
	//ans = max(ans, temp);
//	cout << u << " " << temp << '\n';
	if(f[temp + 1] > a[u]){
		ans = max(ans, temp);
		f[temp + 1] = a[u];
	}
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
	}
	f[temp + 1] = pref;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while(t --){
		int x;
		cin >> x;
		//ans = 0;
		for(int i = 1; i <= n; i++){
			f[i] = INF;
			//res[i] = 1;
		}
		f[1] = a[x];
		ans = 0;
		f[0] = 0;
		dfs(x, 0); 
		cout << ans << '\n';
	}
}