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

int n, p[100003][20], log2_n;

vector < int > adj[100003];

void dfs(int u) {
	for (auto v : adj[u]) {
		if (v == p[u][0]) continue;
		p[v][0] = u;
		dfs(v);
	}
}

void init() {
	p[1][0] = -1;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) p[i][j] = -1;
	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];

}

int query(int u, int v) {
	if (v > n) return -1;
	ll ans = u;
	for (int j = log2_n; j >= 0; j--) {
		if (v >= (1 << j)) {
			v -= (1 << j);
			ans = p[ans][j];
			if (ans == -1) return ans;
		}
	}
	return ans;
}

void sol() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	init();
	int q;
	cin >> q;
	while (q --) {
		int u, v;
		cin >> u >> v;
		cout << query(v, u) << '\n';
	}
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
