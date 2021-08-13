#include <bits/stdc++.h>

using namespace std;

int n;

long long sum = 0, cnt = 0;

vector < int > adj[100005];

void dfs(int u, int e){
	sum += cnt;
	for(auto v : adj[u]){
		if(v == e) continue;
		cnt ++;
		dfs(v, u);
	}
	cnt --;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SumDisV1.inp", "r", stdin);
	freopen("SumDisV.1out", "w", stdout);

	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << sum;
}