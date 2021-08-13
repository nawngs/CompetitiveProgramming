//link: https://oj.vnoi.info/problem/graph_
#include <bits/stdc++.h>

using namespace std;

int n, m, bridges = 0, num[10005], tail[10005], low[10005], timeDFS = 0;

bool joint[10005];

vector < int > adj[10005];

void dfs(int u, int pre){
	num[u] = low[u] = ++ timeDFS;
	int child = 0;
	for(auto v : adj[u]){
		if(v == pre) continue;
		if(!num[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			child ++;
			if(num[v] == low[v]) bridges ++;
			if(pre == 0){
				if(child > 1) joint[u] = true;
			}
			else if(low[v] >= num[u]) joint[u] = true;
		}
		else low[u] = min(low[u], num[v]);
	}
	tail[u] = timeDFS;
}

int main(){
	memset(joint, false, sizeof(joint));
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
		if(num[i] == 0) dfs(i, 0);


	int cnt = 0;
	for(int i = 1; i <= n; i++) if(joint[i] == true) cnt ++;
	cout << cnt << " " << bridges;
}