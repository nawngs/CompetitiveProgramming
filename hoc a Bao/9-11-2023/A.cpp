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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

using vi = vector < int >;

int n, t, m;

vi id[N + 3];

stack < int > upd[N + 3];

bool vs[N + 3];

map < int, vi > adj[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> t;
	for (int i = 1; i <= t; i++) {
		int sze; cin >> sze;                                                                                              
		while (sze--) {
			int u, v; cin >> u >> v;
			adj[i][u].pb(v); adj[i][v].pb(u);
			id[u].pb(i); id[v].pb(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(id[i].begin(), id[i].end());
		id[i].erase(unique(id[i].begin(), id[i].end()), id[i].end());
	}
	for (auto x : id[1]) upd[x].push(1);
	vs[1] = 1;
	int k; cin >> k;
	stack < int > newu;
	for (int res = 1; res <= k; res++) {
		int u; cin >> u;
		while (!upd[u].empty()) {
			auto v = upd[u].top(); upd[u].pop();
			for (auto x : adj[u][v]) if (!vs[x]) {
				newu.push(x);
				vs[x] = 1;
			}
		}
		if (vs[n]) {
			cout << res << '\n';
			return 0;
		}
		while (!newu.empty()) {
			auto v = newu.top(); newu.pop();
			for (auto x : id[v]) upd[x].push(v);
		}
	}
	cout << -1 << '\n';
}