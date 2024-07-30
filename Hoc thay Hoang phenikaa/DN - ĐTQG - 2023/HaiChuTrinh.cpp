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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, par[N + 3];

set < vector < int > > res;

bool ok[N + 3];

vector < int > adj[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= 2 * n - 3; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	vector < int > temp;
	for (int u = 1; u <= n; u++) {
		sort(adj[u].begin(), adj[u].end(), [&](int &x, int &y) {
			return adj[x].size() > adj[y].size();
		});
		for (auto v : adj[u]) ok[v] = 1;
		for (auto v : adj[u]) {
			if (adj[v].size() < adj[u].size()) break;
			for (auto x : adj[v]) {
				if (ok[x]) {
					temp.clear();
					temp.pb(u); temp.pb(v); temp.pb(x);
					sort(temp.begin(), temp.end());
					res.insert(temp);
					if (res.size() >= 2) {
						cout << 3 << '\n';
						for (int i = 0; i < 2; i++) {
							for (auto x : *res.begin()) cout << x << " ";
							cout << '\n';
							res.erase(res.begin());
						}
						return 0;
					}
				}
			}
		}
		for (auto v : adj[u]) ok[v] = 0;
	}
	if (res.size() < 0) cout << res.size() << '\n';
	else  {
		cout << 3 << '\n';
		for (int i = 0; i < (res.size(), 2); i++) {
			for (auto x : *res.begin()) cout << x << " ";
			cout << '\n';
			res.erase(res.begin());
		}
	}
	
}