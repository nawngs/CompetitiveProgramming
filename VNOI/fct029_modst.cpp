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
const int M = 1e7;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, f[M + 3], par[N + 3];

vector < int > a;

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector < Edge > eds;

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	a.resize(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	memset(f, 255, sizeof f);
	for (int i = 0; i < n; i++) f[a[i]] = i; 
	for (int j = M; j >= 1; j--) if (f[j] == -1) f[j] = f[j + 1];
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = x; j <= M; j+=x) {
			if (f[j] != -1 && a[f[j]] < j + x) {
				assert(0 <= f[j] && f[j] < n);
				eds.pb({i, f[j], a[f[j]] % x});
				if (f[j + 1] != -1 && f[j + 1] != f[j] && a[f[j + 1]] < j + x) eds.pb({i, f[j + 1], a[f[j + 1]] % x});
			}
		}	
	}
	sort(eds.begin(), eds.end(), [&](Edge &x, Edge &y) {
		return x.w < y.w;
	});
	for (int i = 0; i < n; i++) par[i] = i;
	ll res = 0;
	for (auto e : eds) 
		if (join(e.u, e.v)) res += 1ll * e.w;
	
	cout << res;
}