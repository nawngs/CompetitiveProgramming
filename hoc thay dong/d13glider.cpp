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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, res = 0, d[NMAX + 3];

pll a[NMAX + 3];

vector < pll > adj[NMAX + 3];

void dijkstra() {
	for (int i = 1; i <= n; i++) d[i] = LINF;
	d[1] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({u.fi + v.se, v.fi});
			}
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		res += a[i].se;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i > 1) adj[i].pb({i - 1, 0});
		int l = i + 1, r = n, mid, ans = n + 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid].fi - a[i].fi - a[i].se > 0) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
			
		}
		if (ans <= n) adj[i].pb({ans, a[ans].fi - a[i].fi - a[i].se});
		adj[i].pb({ans - 1, 0});
	}
	dijkstra();
	cout << d[n] + res;
}