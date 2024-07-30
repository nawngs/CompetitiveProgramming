#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const ll MAXT = NMAX * NMAX;

int n, m, minc[NMAX + 3];

ll res[NMAX + 3];

vector < tuple < int, int, int > > adj[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, t, c; cin >> u >> v >> t >> c;
		adj[u].pb({v, t, c}); adj[v].pb({u, t, c});
	}
	for (int i = 1; i <= n; i++) 
		res[i] = LINF, minc[i] = INF;
	res[1] = minc[1] = 0;
	priority_queue < tuple < int, int, int >, vector < tuple < int, int , int > >, greater < tuple < int, int, int > > > heap;
	heap.push({0, 0, 1});
	while (!heap.empty()) {
		int curt, curc, u; tie(curt, curc, u) = heap.top(); heap.pop();
		res[u] = min(res[u], 1ll * curt * 1ll * curc);
		if (minc[u] < curc) continue;
		minc[u] = curc;
		for (auto x : adj[u]) {
			int v, t, c; tie(v, t, c) = x;
			if (curt + t > MAXT) continue;
			heap.push({curt + t, curc + c, v});
		}
	}
	for (int i = 2; i <= n; i++) cout << (res[i] == LINF ? -1 : res[i]) << '\n';
}