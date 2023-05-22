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

struct Edge {
	int u, v, c;
} a[10003];

int n, m, par[1003], sze[1003];

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return ;
	if (sze[u] < sze[v]) swap(u, v);
	sze[u] += sze[v];
	par[v] = u;
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].c;
	sort(a + 1, a + m + 1, [&](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	int r = 0, diff = INF, val1, val2;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			par[j] = j;
			sze[j] = 1;
		}
		for (int j = i; j <= r; j++)
			merge(a[j].u, a[j].v);
		while (r < m && sze[find(1)] != n) {
			r ++;
			merge(a[r].u, a[r].v);
		}
		if (sze[find(1)] != n) break;
		if (a[r].c - a[i].c < diff) {
			diff = a[r].c - a[i].c;
			val1 = a[i].c;
			val2 = a[r].c;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sze[i] << '\n';
	}
	for (int j = 1; j <= n; j++) {
		
	}
	cout << val1 << " " << val2 << '\n';
}
