//link:https://oj.vnoi.info/problem/tjalg

#include <bits/stdc++.h>

using namespace std;

int n, m, num[100005], low[100005], scc = 0, timeDFS = 0;

bool deleted[100005];

vector < int > adj[100005];

stack < int > st;

void dfs(int u) {
	num[u] = low[u] = ++timeDFS;
	st.push(u);
	for (auto v : adj[u]) {
		if(deleted[v]) continue;
		if(!num[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u]){
		scc ++;
		while (st.top() != u) {
			deleted[st.top()] = true;
			st.pop();
		}
		deleted[st.top()] = true;
		st.pop();
	}
}

int main() {
	cin >> n >> m;
	memset(deleted, false, sizeof(deleted));
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (num[i] == 0) dfs(i);
	cout << scc;
}