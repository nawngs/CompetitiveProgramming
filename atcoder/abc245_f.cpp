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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, ans = 0, num[200003], low[200003], timeDFS;

bool check[200003], intam[200003];

vector < int > adj[200003], tam;

void dfs(int u) {
	num[u] = low[u] = ++timeDFS;
	tam.push_back(u);
	intam[u] = 1;
	bool th = false;
	for (auto v : adj[u]) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else {
			if (intam[v]) low[u] = min(low[u], num[v]);
			else th = (th || check[v]);
			
		}
	}
	if (low[u] < num[u] || th) {
		ans += tam.size();
		while (tam.size()) {
			check[tam.back()] = 1;
			tam.pop_back();
		}
	}
	if (tam.back() == u) tam.pop_back();
	intam[u] = 0;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
