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

ll n, m, d[2503], pre[2503];

bool check[2503], th = false;

vector < pll > adj[2503];

void fordbellman(int st) {
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[st] = 0;
	for (int i = 1; i <= n; i++) {
		bool adjust = false;
		for (int u = 1; u <= n; u++) {
			if (d[u] != INF) {
				check[u] = 1;
				for (auto v : adj[u]) {
					if (d[v.fi] > d[u] + v.se) {
						d[v.fi] = d[u] + v.se;
						pre[v.fi] = u;
						adjust = 1;
					}
				}
			}
		}
		if (!adjust) break;
	}
	int x = -1;
	for (int u = 1; u <= n; u++) {
		if (d[u] != INF) {
			for (auto &v : adj[u]) {
				if (d[v.fi] > d[u] + v.se) {
					d[v.fi] = d[u] + v.se;
					pre[v.fi] = u;
					x = v.fi;
				}
			}
		}
	}
	if (x != -1) {
		th = 1;
		for (int i = 1; i <= n; i++) x = pre[x];
		vector < int > cycle;
		int v = x;
		cycle.push_back(v);
		v = pre[v];
		while (v != x) {
			cycle.push_back(v);
			v = pre[v];
		}
		cycle.push_back(v);
		reverse(cycle.begin(), cycle.end());
		cout << "YES" << '\n';
		for (auto x : cycle) cout << x << ' ';
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) fordbellman(i);
		if (th) return ;
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
