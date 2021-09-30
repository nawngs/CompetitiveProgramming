#include <bits/stdc++.h>

using namespace std;

int t, f[200005], n, cnt[200005];

vector < int > adj[200005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		f[i] = 0;
		adj[i].clear();
	}
	queue < int > q;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		for (int j = 1; j <= f[i]; j++) {
			int x;
			cin >> x;
			adj[x].push_back(i);
		}
		if (f[i] == 0) {
			q.push(i);
			cnt[i] = 1;
		}
	}
	int res = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			f[v] --;
			if (f[v] == 0) {
				q.push(v);
				if (v < u) cnt[v] = cnt[u] + 1;
				else cnt[v] = cnt[u];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] != 0) {
			cout << -1 << '\n';
			return;
		}
		res = max(res, cnt[i]);
	}
	cout << res << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}