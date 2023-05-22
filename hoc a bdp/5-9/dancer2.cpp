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

int n, m, res = 0;

bool vs[200003];

vector < int > adj[200003];

void dfs(int u, int e) {
	cout << u << " " << e << '\n';
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (vs[v]) {
			//cout << u << " " << v << '\n';
			res ++;
			continue;
		}
		dfs(v, u);
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		v += n;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << res / 2;
}
