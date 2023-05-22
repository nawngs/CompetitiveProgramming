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

int n, res[500003], min_child[500003], cnt = 0;

vector < int > adj[500003];

void dfs_pre(int u, int e) {
	min_child[u] = (res[u] == 0 ? u : INF);
	for (auto v : adj[u]) {
		if (v == e || res[v] != 0) continue;
		dfs_pre(v, u);
		min_child[u] = min(min_child[u], min_child[v]);
	}
}

void paint(int u, int e, int val) {
	res[u] = val;
	vector < pii > temp;
	for (auto v : adj[u]) {
		if (v == e || res[v] != 0) continue;
		temp.push_back({min_child[v], v});
	}
	sort(temp.begin(), temp.end());
	if (temp.size()) paint(temp[0].se, u, val);
}

void dfs(int u, int e, int val) {
	dfs_pre(u, e);
	res[u] = val;
	vector < pii > temp;
	for (auto v : adj[u]) {
		if (v == e || res[v] != 0) continue;
		temp.push_back({min_child[v], v});
	}
	sort(temp.begin(), temp.end());
	int dem = 0;
	for (auto x : temp) {
		if (dem == 2) break;
		paint(x.se, u, val);
		dem ++;
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
	for (int i = 1; i <= n; i++) {
		if (!res[i]) dfs(i, 0, ++ cnt);
		cout << res[i] << ' ';
	}	
}
