#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }

struct Stick {
	double x, y, u, v, t;
} a[103];

int n, cnt;

double d[203], val;

vector < pair < int, double > > adj[203];

map < pair < double, double >, int > f;

void add_edge(double x, double y, double u, double v, double t) {
	int pos1, pos2;
	if (f.find({x, y}) == f.end()) {
		f[{x, y}] = ++ cnt;
		pos1 = cnt;
	}
	else pos1 = f[{x, y}];
	if (f.find({u, v}) == f.end()) {
		f[{u, v}] = ++ cnt;
		pos2 = cnt;
	}
	else pos2 = f[{u, v}];
	adj[pos1].push_back({pos2, t}); adj[pos2].push_back({pos1, t});
}

void get_res(double x, double y, double u, double v, double t) {
	int pos1 = f[{x, y}], pos2 = f[{u, v}];
	double rem = t - abs(d[pos1] - d[pos2]);
	val = max(val, max(d[pos1], d[pos2]) + rem / 2);
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
		cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v >> a[i].t;
		double x = (a[i].x + a[i].u) / 2, y = (a[i].y + a[i].v) / 2;
		a[i].t /= 2;
		a[i + n] = a[i];
		a[i].u = a[i + n].x = x;
		a[i].v = a[i + n].y = y;
	}
	n = n + n;
	for (int i = 1; i <= n; i++) add_edge(a[i].x, a[i].y, a[i].u, a[i].v, a[i].t);
	double res = INF;
	for (auto start : f) if (start.fi.fi == floor(start.fi.fi) && start.fi.se == floor(start.fi.se)) {
		for (int i = 1; i <= cnt; i++) d[i] = INF;
		d[start.se] = 0; 
		priority_queue < pair < double, int >, vector < pair < double, int > >, greater < pair < double, int > > > heap;
		heap.push({0, start.se});
		while (!heap.empty()) {
			auto u = heap.top(); heap.pop();
			if (d[u.se] != u.fi) continue;
			for (auto v : adj[u.se]) 
				if (minimize(d[v.fi], u.fi + v.se)) 
					heap.push({d[v.fi], v.fi});
		}
		val = 0;
		for (int i = 1; i <= n; i++) get_res(a[i].x, a[i].y, a[i].u, a[i].v, a[i].t);
		res = min(res, val);
	}
	cout << fixed << setprecision(2) << res;
}
