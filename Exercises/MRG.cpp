#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, m;

struct Edges {
	int u, v, p, c;
	Edges(int _u, int _v, int _p, int _c) : u(_u), v(_v), p(_p), c(_c) {};
};

bool f[50005];

vector < Edges > car, motor;

struct Dsu {
	vector < int > par;
	
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i; 
	}

	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}

	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}
	bool check(int n) {
		int root = find_root(1);
		for (int i = 1; i <= n; i++) if (find_root(i) != root) return false;
		return true;
	}

} dsu_car, dsu_motor;

int main() {
	fastflow;
	freopen("MRG.INP", "r", stdin);
	freopen("MRG.OUT", "w", stdout);
	cin >> n >> m;
	dsu_car.init(n);
	memset(f, false, sizeof(f));
	dsu_motor.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (c == 2) {
			car.push_back({u, v, i, c});
			motor.push_back({u, v, i, c});
		}
		if (c == 1) motor.push_back({u, v, i, c});
		if (c == 3) car.push_back({u, v, i, c});
	}
	sort(car.begin(), car.end(), [](Edges &x, Edges &y) {
		return x.c < y.c;
	});
	sort(motor.begin(), motor.end(), [](Edges &x, Edges &y) {
		return x.c > y.c;
	});
	for (auto e : car) {
		if (dsu_car.join(e.u, e.v)) {
			f[e.p] = true;
			if (e.c == 2) dsu_motor.join(e.u, e.v);
		}
	}
	if (!dsu_car.check(n)) {
		cout << -1 << '\n';
		return 0;
	}
	for (auto e : motor) {
		if (dsu_motor.join(e.u, e.v)) {
			f[e.p] = true;
		}
	}
	if (!dsu_motor.check(n)) {
		cout << -1 << '\n';
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) ans += (f[i] == false);
	memset(f, false, sizeof(f));
	dsu_motor.init(n);
	dsu_car.init(n);
	for (auto e : motor) {
		if (dsu_motor.join(e.u, e.v)) {
			f[e.p] = true;
			if (e.c == 2) dsu_car.join(e.u, e.v);
		}
	}
	for (auto e : car) {
		if (dsu_car.join(e.u, e.v)) {
			f[e.p] = true;
		}
	}
	ll ans2 = 0;
	for (int i = 1; i <= m; i++) ans2 += (f[i] == false);
	cout << min(ans, ans2);
}
