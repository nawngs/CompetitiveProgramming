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

ll n, a[500003], ans = 0, par[500003][22], root;

vector < int > adj[500003];

void dfs(int u, int e = 0) {
	par[u][0] = e;
	for (int i = 1; i <= 20; i++) if (par[u][i - 1] != 0) par[u][i] = par[par[u][i - 1]][i - 1];
	ll mina = LINF;
	for (int i = 0; i <= 20; i++) {
		if (par[u][i] == 0) {
			mina = min(mina, (i + 1) * a[root] + a[u]);
			break;
		}
		mina = min(mina, (i + 1) * a[par[u][i]] + a[u]);
	}
	if (e != 0) ans += mina;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
}

int main() {
	fast;
	cin >> n;
	root = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (root == -1 || a[i] < a[root]) root = i;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(root);
	cout << ans;
}
