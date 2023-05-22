#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < ll, pll >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "service";
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

ll n, m, k, d[503], pre[503];

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return false;
}

vector < pll > adj[503];

int main() {
	fast;
	fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	while (k--) {
		ll res = 0;
		priority_queue < pll, vector < pll >, greater < pll > > heap;
		for (int i = 1; i <= n; i++) d[i] = pre[i] = LINF;
		for (int i = 1; i <= 3; i++) {
			int u; cin >> u;
			d[u] = pre[u] = 0;		
			heap.push({d[u], u});
		}
		while (heap.size()) {
			auto x = heap.top(); heap.pop();
			int dis = x.fi, u = x.se;
			if (dis != d[u]) continue;
			res += pre[u];
			for (auto v : adj[u]) {
				if (minimize(d[v.fi], dis + v.se)) {
					pre[v.fi] = v.se;
					heap.push({d[v.fi], v.fi});
				}
				if (d[v.fi] == dis + v.se) pre[v.fi] = min(pre[v.fi], v.se);
			}
		}
		cout << 100 * res << '\n';
	}
}
