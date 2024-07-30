//[FINISHED]
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, res[5003];

vector < int > adj[5003];

int vs[5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0, len = 0;
		queue < pii > que;
		que.push({i, 0});
		vs[i] = i;
		while (que.size()) {
			auto u = que.front(); que.pop();
			cnt ++; len += u.se;
			res[cnt] = max(res[cnt], cnt * (n - cnt) + cnt * (cnt - 1) - 2 * len);
			for (auto v : adj[u.fi]) if (vs[v] != i) {
				que.push({v, u.se + 1});
				vs[v] = i;
			} 
		}
	}
	for (int i = 0; i <= n; i++) cout << res[i] << " ";
}