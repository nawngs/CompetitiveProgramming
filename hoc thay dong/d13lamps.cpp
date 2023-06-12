#include <bits/stdc++.h>

using namespace std;

int n, t, val[3001];

bitset < 3502 > a[3001];

vector < int > adj[3001];

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		a[i][i] = 1;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			a[j][i + n] = 1 - x;
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = j; i <= n; i++) if (a[i][j]) {
			swap(a[i], a[j]);
			break;
		}
		for (int i = 1; i <= n; i++) if (a[i][j] && i != j)
			a[i] ^= a[j];
	}
	for (int tt = 1; tt <= t; tt++) {
		vector < int > res;
		bool th = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i][i] == 0 && a[i][n + tt] == 1) {
				cout << -1 << '\n';
				th = false;
				break;
			}
			if (a[i][i] && a[i][n + tt]) res.push_back(i);
		}
		if (!th) continue;
		cout << res.size() << " ";
		for (auto x : res) cout << x << " ";
		cout << '\n';
	}	
}