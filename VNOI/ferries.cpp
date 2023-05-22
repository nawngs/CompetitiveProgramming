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

int n, m, d[100003];

vector < int > adj[100003], rev[100003];

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(c);
		rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[n] = 0;
	heap.push({d[n], n});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : rev[u.se]) {
			if (d[v] > u.fi + adj[v].back()) {
				d[v] = u.fi + adj[v].back();
				heap.push({d[v], v});
			}
			adj[v].pop_back();
		}
	}
	cout << d[1];
}
