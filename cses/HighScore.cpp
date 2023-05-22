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

ll n, m, d[2503];

vector < pll > adj[2503];

void fordbellman() {
	for (int i = 1; i <= n; i++) d[i] = -INF;
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		bool adjust = false;
		for (int u = 1; u <= n; u++) {
			if (d[u] != -INF) {
				for (auto v : adj[u]) {
					if (d[v.fi] < d[u] + v.se) {
						d[v.fi] = d[u] + v.se;
						adjust = 1;
					}
				}
			}
		}
		if (!adjust) break;
	}
	ll tam1 = d[1], tam2 = d[n];
	for (int u = 1; u <= n; u++) if (d[u] != -INF) for (auto v : adj[u]) if (d[v.fi] < d[u] + v.se) d[v.fi] = d[u] + 1e15;
	for (int u = 1; u <= n; u++) if (d[u] != -INF) for (auto v : adj[u]) if (d[v.fi] < d[u] + v.se) d[v.fi] = d[u] + 1e15;
	if (d[1] != tam1 || d[n] != tam2) cout << -1;
	else cout << d[n];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
	}
	fordbellman();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
