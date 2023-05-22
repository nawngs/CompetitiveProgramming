	#pragma GCC optimize ("O2")
	#include <bits/stdc++.h>

	#define ll long long
	#define ld long double
	#define fi first 
	#define se second
	#define pll pair < ll, ll >
	#define pii pair < int, int >
	#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	using namespace std;

	const string NAME = "";
	const string NAME2 = "TEST";
	const ld ESP = 1e-9;
	const ll INF = 1e9 + 7;
	const ll LINF = 1E18;
	const ll nmax = 2e5;
	const ll MOD = 1e9 + 7;
	const ll base = 2309;

	void fre() {
		string finp = NAME + ".inp";
		string fout = NAME + ".out";
		freopen(finp.c_str(), "r", stdin);
		freopen(fout.c_str(), "w", stdout);
	}

	int n, pos[1000003], h[1000003];

	vector < int > adj[1000003];

	map < int, int > val[1000003];

	void dfs(int u = 1, int e = 0) {
		val[u][h[u]] = 1;
		int ans = 1;
		for (auto v : adj[u]) {
			if (v == e) continue;
			h[v] = h[u] + 1;
			dfs(v, u);
			if (val[v].size() > val[u].size()) {
				if (val[v][pos[v] + h[v]] > ans) {
					ans = val[v][pos[v] + h[v]];
					pos[u] = pos[v] + 1;
				}
				if (val[v][pos[v] + h[v]] == ans && pos[v] + 1 < pos[u]) pos[u] = pos[v] + 1;
				swap(val[u], val[v]);
			}
			for (auto x : val[v]) {
				val[u][x.fi] += x.se;
				if (val[u][x.fi] > ans) {
					ans = val[u][x.fi];
					pos[u] = x.fi - h[u];
				}
				else if (val[u][x.fi] == ans && x.fi - h[u] < pos[u]) pos[u] = x.fi - h[u];
			}
		}
	}

	int main() {
		fast;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs();
		for (int i = 1; i <= n; i++) cout << pos[i] << '\n';
	}
	 