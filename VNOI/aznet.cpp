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
const ll INF = 2e9 + 7;
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

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_u = find_root(par[u]);
		int root_v = find_root(par[v]);
		if (root_v == root_u) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu1;

struct Edge {
	int u, v;
} edges[100003];

int n, m, a[100003], b[100003];

vector < int > id[3];

bool used[100003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) used[i] = false;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	id[1].clear();
	id[2].clear();
	dsu1.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges[i].u = u;
		edges[i].v = v;
		id[c].push_back(i);
	}
	int l = 0;
	for (auto c : id[2]) {
		int u = edges[c].u, v = edges[c].v;
		dsu1.join(u, v);
	}
	for (auto c : id[1]) {
		int u = edges[c].u, v = edges[c].v;
		if (dsu1.join(u, v)) {
			used[c] = 1;
			l ++;
		}
	}
	int r = l;
	dsu1.init(n);
	for (int i = 1; i <= m; i++) 
		if (used[i]) dsu1.join(edges[i].u, edges[i].v);
	for (auto c : id[1]) {
		int u = edges[c].u, v = edges[c].v;
		if (dsu1.join(u, v)) r ++;
	}
	int ans = INF, pos = -1;
	for (int i = l; i <= r; i++) {
		if (ans > a[i] + b[n - i - 1]) {
			ans = a[i] + b[n - i - 1];
			pos = i;
		}
	}
	dsu1.init(n);
	for (int i = 1; i <= m; i++) 
		if (used[i]) {
			cout << i << ' ';
			dsu1.join(edges[i].u, edges[i].v);
		}
	pos -= l;
	for (auto c : id[1]) {
		if (!pos) break;
		int u = edges[c].u, v = edges[c].v;
		if (dsu1.join(u, v)) {
			cout << c << " ";
			pos --;
		}
	}
	for (auto c : id[2]) {
		int u = edges[c].u, v = edges[c].v;
		if (dsu1.join(u, v)) cout << c << ' ';
	}
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
