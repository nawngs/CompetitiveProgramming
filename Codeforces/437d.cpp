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

ll n, m, a[100003], b[100003], par[100003], rnk[100003];

ld s = 0;

vector < int > adj[100003];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v, ll val) {
	u = find(u);
	v = find(v);
	if (u == v)
		return ;
	s += val * rnk[u] * rnk[v];
	par[v] = u;
	rnk[u] += rnk[v];
	return ;
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = i;
		par[i] = i;
		rnk[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (a[u] > a[v]) 
			swap(u, v);
		adj[u].push_back(v);
	}
	sort(b + 1, b + n + 1, [&](ll &x, ll &y) {
		return a[x] > a[y];
	});
	for (int i = 1; i <= n; i++) {
		for (auto v : adj[b[i]]) 
			merge(b[i], v, a[b[i]]);
	}
	cout << fixed << setprecision(9) << s / (ld) (n * (n - 1) / 2) << '\n';
}
