#include <bits/stdc++.h>

using namespace std;

int n, t, k, cnt;

vector < int > adj[100005];

vector < int > temp;

void dfs(int u, int e){
	cnt ++;
	temp.push_back(u);
	if(cnt == k){
		for(int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
		cout << '\n';
		return ;
	}
	for(auto v : adj[u]){
		if(v == e) continue;
		dfs(v, u);
		if(cnt == k) return ;
	}
	temp.pop_back();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("KPATH.inp", "r", stdin);
	freopen("KPATH.out", "w", stdout);
	cin >> n >> t;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	while(t --){
		cin >> k;
		int start = (k + n - 1) / n;
		cnt = 0;
		k %= n;
		if(k == 0) k += n;
		temp.clear();
		dfs(start, 0);
	}
}
