#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, f[NMAX + 3], d[2 * NMAX + 3];

bool th[NMAX + 3];

vector < pii > adj[2 * NMAX + 3];

map < int, bool > connected[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 1; i <= NMAX; i++) f[i] = i;
	for (int i = 2; i * i <= NMAX; i++) 
		if (f[i] == i) 
			for (int j = 2 * i; j <= NMAX; j+=i) f[j] = i;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		while (x > 1) {
			if (!connected[f[x]][i]) {
				adj[f[x]].pb({i + NMAX, 1}); adj[i + NMAX].pb({f[x], 0});
				connected[f[x]][i] = 1;
			}
			x /= f[x];
		}
	}
	int s, t; cin >> s >> t;
	for (int i = 1; i <= NMAX + n; i++)
		d[i] = INF;
	d[s + NMAX] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	heap.push({0, s + NMAX});
	while (sz(heap)) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	cout << (d[t + NMAX] == INF ? -1 : d[t + NMAX] + 1);
}