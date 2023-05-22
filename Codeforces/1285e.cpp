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

int n, f[200003], g[200003], minl[200003];

pii a[200003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return x.se < y.se;
	});
	g[n] = 1, minl[n] = a[n].fi;
	for (int i = n - 1; i >= 1; i--) {
		g[i] = g[i + 1] + (minl[i + 1] > a[i].se);
		minl[i] = min(minl[i + 1], a[i].fi);
	}
	int res = 0;
	vector < int > vec; vec.push_back(-INF);
	for (int i = 1; i < n; i++) { 
		int it = lower_bound(vec.begin(), vec.end(), minl[i + 1]) - vec.begin();
		it --;
		res = max(res, g[i + 1] + it);
		while (sz(vec) && vec.back() >= a[i].fi) 
			vec.pop_back();
		vec.push_back(a[i].se);
	}
	cout << max(res, sz(vec) - 1) << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}