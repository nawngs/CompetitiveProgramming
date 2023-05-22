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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, s, t;

ll d[203];

vector < pii > point[203];

vector < pll > adj[203];

ll ll_dis(pii x, pii y) {
    return 1LL * (y.fi - x.fi) * (y.fi - x.fi) + 1LL * (y.se - x.se) * (y.se - x.se);
}
double dis(pii x, pii y) {
    return sqrt(1LL * (x.fi - y.fi) * (x.fi - y.fi) + 1LL * (x.se - y.se) * (x.se - y.se));
}
double dis_line(pii x, pii y, pii z) {
    if (ll_dis(x, y) + ll_dis(y, z) <= ll_dis(x, z)) return dis(x, y);
    if (ll_dis(x, z) + ll_dis(y, z) <= ll_dis(x, y)) return dis(x, z);
    pii xy = {y.fi - x.fi, y.se - x.se};
    pii xz = {z.fi - x.fi, z.se - x.se};
    long double X = abs(1LL * xy.fi * xz.se - 1LL * xy.se * xz.fi);
    return X / dis(y, z);
}

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		point[i].resize(k);
		for (auto &x : point[i]) cin >> x.fi >> x.se;
		d[i] = LINF;
	}
	d[s] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			double dis = LINF;
			for (auto a : point[i]) 
				for (int k = 0; k < sz(point[j]) - 1; k++) 
					minimize(dis, dis_line(a, point[j][k], point[j][k + 1]));
			adj[i].push_back({j, (ll)((ld)NMAX * dis)});
			adj[j].push_back({i, (ll)((ld)NMAX * dis)});
		}
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, s});
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		if (u.se == t) {
			cout << u.fi << '\n';
			return 0;
		}
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (minimize(d[v.fi], v.se + u.fi)) 
				heap.push({d[v.fi], v.fi});
		}
	}
}