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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, vertex, edges, ans = 1;

bool visited[200003];

vector < int > adj[200003];

void dfs(int u) {
	visited[u] = 1;
	vertex ++;
	edges += adj[u].size();
	for (auto v : adj[u]) if (!visited[v]) dfs(v);
}

void sol() {
	cin >> n >> m;
	if (m != n) {
		cout << 0;
		return ;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		if (!visited[i]) {
			vertex = 0;
			edges = 0;
			dfs(i);
			if (edges == vertex * 2) ans = (ans * 2) % MOD;
			else {
				cout << 0;
				return ;
			}
		}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
