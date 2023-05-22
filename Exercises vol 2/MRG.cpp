#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "mrg";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v, c, id;
	Edge(int _u, int _v, int _c, int _id) : u(_u), v(_v), c(_c), id(_id){};
};

vector < Edge > motor, car;

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
		for (int i = 2; i <= n; i++) if (join(1, i)) return false;
		return true;
	}

} dsu_motor, dsu_car;

int n, m;

bool used[50003];

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (c == 2) {
			motor.push_back({u, v, c, i});
			car.push_back({u, v, c, i});
		}
		if (c == 1) motor.push_back({u, v, c, i});
		if (c == 3) car.push_back({u, v, c, i});
	}
	sort(motor.begin(), motor.end(), [&](Edge &x, Edge &y) {
		return x.c > y.c;
	});
	sort(car.begin(), car.end(), [&](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	dsu_car.init(n);
	dsu_motor.init(n);
	for (auto e : car) {
		if (dsu_car.join(e.u, e.v)) {
			used[e.id] = 1;
			if (e.c == 2) dsu_motor.join(e.u, e.v);
		}
	}
	if (!dsu_car.check(n)) {
		cout << -1 << '\n';
		return 0;
	}
	for (auto e : motor) if (dsu_motor.join(e.u, e.v)) used[e.id] = 1;
	if (!dsu_motor.check(n)) {
		cout << -1 << '\n';
		return 0;
	}
	int res = 0;
	for (int i = 1; i <= m; i++) res += !used[i];
	cout << res;
}
