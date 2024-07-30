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
const ll LINF = 1E12;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, st, fn, k, p[NMAX + 3], d[NMAX + 3], res[NMAX + 3], pos[NMAX + 3];

vector < pll > adj[NMAX + 3];

ll calc(int id) {
	//cout << id << '\n';
 	for (int i = 1; i <= n; i++) d[i] = LINF;
	d[st] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) if (pos[v.se] <= id) {
			if (d[v.fi] > u.fi + pos[v.se]) {
				d[v.fi] = u.fi + pos[v.se];
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	//if (id == 3) cout << d[fn] << '\n';
	return d[fn];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> st >> fn >> k;
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb({v, i}); adj[v].pb({u, i});
	}
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (calc(mid) <= k) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans == -1) {
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	for (int i = 1; i < ans; i++) res[p[i]] = i;
	res[p[ans]] = ans + k - calc(ans);
	for (int i = ans + 1; i <= m; i++) res[p[i]] = k + i - ans;
	for (int i = 1; i <= m; i++) cout << res[i] << " ";	
}