#include <bits/stdc++.h>

#define name "rowing"
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

ll n, d[4005], h;

pll a[4005];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	for (int i = 1; i <= n + 2; i++) d[i] = LINF;
	d[n + 1] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, n + 1});
	while (sz(heap)) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		if (u.se == n + 2) {
			ll temp = sqrtl(u.fi);
			cout << temp + (temp * temp != u.fi) << '\n';
			return 0;
		}
		if (u.se == n + 1) {
			for (int i = 1; i <= n; i++) {
				ll w = a[i].se * a[i].se, newv = max(u.fi, w);
				if (d[i] > newv) {
					//cout << i << " " << newv << '\n';
					d[i] = newv;
					heap.push({d[i], i});
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (i == u.se) continue;
				ll dis = (a[i].fi - a[u.se].fi) * (a[i].fi - a[u.se].fi) + (a[i].se - a[u.se].se) * (a[i].se - a[u.se].se);
				dis = max(dis, u.fi);
				if (d[i] > dis) {
					d[i] = dis;
					heap.push({d[i], i});
				}
			}
			ll dis = h - a[u.se].se; dis *= dis;
			if (d[n + 2] > max(dis, u.fi)) {
				d[n + 2] = max(dis, u.fi);
				heap.push({d[n + 2], n + 2});
			}
		}

	}

}