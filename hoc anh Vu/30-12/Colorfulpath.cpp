#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plii pair < ll, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Edge {
	ll v, c, w;
	Edge (ll _v, ll _c, ll _w) : v(_v), c(_c), w(_w) {};
};

int n, m, C, color[100003][2], s;

ll d[100003][2];

vector < Edge > adj[100003];

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return 1;
	}
	else return 0;
}

void dijkstra() {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 2; j++) {
			d[i][j] = LINF;
			color[i][j] = -1;
		}
	priority_queue < plii, vector < plii >, greater < plii > > heap;
	d[s][0] = 0; color[s][0] = 0;
	heap.push({0, {s, 0}});
	while (sz(heap)) {
		auto x = heap.top(); heap.pop();
		ll val = x.fi, u = x.se.fi, i = x.se.se;
		if (i != color[u][1] && i != color[u][0]) continue;
		if (i == color[u][0] && val != d[u][0]) continue;
		if (i == color[u][1] && val != d[u][1]) continue;
		for (auto y : adj[u]) {
			ll v = y.v, c = y.c, w = y.w;
			if (c == i) continue;
			if (color[v][0] == c) {
				if (minimize(d[v][0], val + w)) 
					heap.push({d[v][0], {v, c}});
			}
			else {
				if (minimize(d[v][1], val + w)) {
					color[v][1] = c;
					heap.push({d[v][1], {v, c}});
				}
			}
			if (d[v][1] < d[v][0]) {
				swap(d[v][1], d[v][0]);
				swap(color[v][1], color[v][0]);
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
	cin >> n >> m >> C;
	for (int i = 1; i <= m; i++) {
		ll u, v, c, w; cin >> u >> v >> w >> c;
		adj[u].push_back({v, c, w});
	}
	cin >> s; dijkstra();
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		cout << (d[t][0] == LINF ? -1 : d[t][0]) << '\n';
	}
}