#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

#include <bits/stdc++.h>

using namespace std;

int n, k, m, ans = 1e9 + 7, vs[23];

bool connected[23][23];

vector < int > adj[100005], e[23]; 

void inp() {
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			adj[x].push_back(i);
		}
	}

}

void build_edge() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			for (int p = j + 1; p < adj[i].size(); p++) {
				if (connected[adj[i][j]][adj[i][p]] == false && connected[adj[i][p]][adj[i][j]] == false){
					//cout << adj[i][j] << " " << adj[i][p] << '\n';
					connected[adj[i][j]][adj[i][p]] = connected[adj[i][p]][adj[i][j]] = true;
					e[adj[i][j]].push_back(adj[i][p]);
					e[adj[i][p]].push_back(adj[i][j]);
				}
			}
		}
	}
	//cout << "YES" << '\n';
}

void bfs(int u) {
	for (int i = 1; i <= m; i++) vs[i] = 1e9 + 7;
	vs[u] = 0;
	queue < int > q;
	q.push(u);
	while (q.size()) {
		int tam = q.front();
		q.pop();
		//cout << tam << " " << vs[tam] << '\n';
		for (auto v : e[tam]) {
			if (vs[v] == 1e9 + 7) {
				vs[v] = vs[tam] + 1;
				q.push(v);
			}
		}
	}
	for (auto v : adj[n]) {
		//cout << vs[v] << '\n';
		ans = min(ans, vs[v]);
	}
}

void xuly() {
	for (auto v : adj[1]) bfs(v);
	//cout << "YES" << '\n';
	if (ans == 1e9 + 7) cout << -1;
	else cout << ans + 2;
}

void sol() {
	inp();
	build_edge();
	xuly();
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sol();

	
}

/*
9 3 5 
1 2 3
1 4 5
3 6 7
5 6 7
6 8 9
 
15 8 4 
11 12 8 14 13 6 10 7
1 5 8 12 13 6 2 4
10 15 4 5 9 8 14 12 7
11 12 14 3 5 6 1 13
*/