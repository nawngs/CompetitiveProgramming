#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9 + 711;

int n, m, cnt[100005], d[100005];

vector < int > adj[100005];

void bfs() {
	queue < int > q;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;
	q.push(1);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				cnt[v] = cnt[u];
				q.push(v); 
			}
			else if (d[v] == d[u] + 1) cnt[v] += cnt[u];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("COMSAFE.INP", "r", stdin);
	freopen("COMSAFE.OUT", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	cnt[1] = 1;
	bfs();
	bool th = false;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 2) {
			cout << i << " " ;
			th = true;
		}
	}
	if (!th) cout << "UNSAFE" << '\n';
}