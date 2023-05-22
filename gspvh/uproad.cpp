#include <bits/stdc++.h>

#define name "UPROAD"
#define test "test"
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
const int NMAX = 150000;
const ll MOD = 1e9 + 7;
const ll BASE = 1E9;

int n, m, uu[NMAX + 3], vv[NMAX + 3], cc[NMAX + 3], gg[NMAX + 3];

vector < int > Ans, cur;

int par[NMAX + 3];

struct Edge {
	int u, v;
	ld c;
	int id;
	Edge (int _u, int _v, ld _c, int _id) {
		u = _u; v = _v; c = _c; id = _id;
	}
};

vector < Edge > edges;

int find(int u) {
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

bool check(ll u) {
	ld val = (u * 1.0) / (BASE * 1.0); 
	edges.clear();
	for (int i = 1; i <= m; i++) 
		edges.pb(Edge(uu[i], vv[i], gg[i] * 1.0 - cc[i] * 1.0 * val, i));
	for (int i = 1; i <= n; i++) 
		par[i] = i;
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.c > y.c;
	});
	ld res = 0;
	cur.clear();
	for (auto e : edges) {
		if (e.c > 0) {
			res += e.c;
			join(e.u, e.v);
			cur.pb(e.id);
			continue;
		}
		if (join(e.u, e.v)) {
			res += e.c;
			cur.pb(e.id);
		}
	}
	if (res > 0) Ans = cur;
	return res > 0;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	int O; cin >> O;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
		cin >> uu[i] >> vv[i] >> cc[i] >> gg[i];
	ll l = 0, r = LINF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	ld res = (ans * 1.0) / (BASE * 1.0);
	cout << fixed << setprecision(8) << res << '\n';
	cout << sz(Ans) << '\n';
	for (auto x : Ans) cout << x << ' ';
}