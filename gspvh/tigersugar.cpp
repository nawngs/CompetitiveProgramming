#include <bits/stdc++.h>

#define int ll
#define name "tigersugar"
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

int n;

pair < pii, pii > schools[100003];

pii store[100003];

vector < int > x, y;

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> schools[i].fi.fi >> schools[i].fi.se >> schools[i].se.fi >> schools[i].se.se;
		if (schools[i].fi.fi > schools[i].se.fi) swap(schools[i].fi.fi, schools[i].se.fi);
		if (schools[i].fi.se > schools[i].se.se) swap(schools[i].fi.se, schools[i].se.se);
		x.push_back(schools[i].fi.fi); x.push_back(schools[i].se.fi);
		y.push_back(schools[i].fi.se); y.push_back(schools[i].se.se);
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	pii mid = mp(x[sz(x) / 2], y[sz(y) / 2]);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (schools[i].fi.fi > mid.fi) store[i].fi = schools[i].fi.fi;
		else if (schools[i].se.fi < mid.fi) store[i].fi = schools[i].se.fi;
		else store[i].fi = mid.fi;
		if (schools[i].fi.se > mid.se) store[i].se = schools[i].fi.se;
		else if (schools[i].se.se < mid.se) store[i].se = schools[i].se.se;
		else store[i].se = mid.se;
		res += abs(store[i].fi - mid.fi) + abs(store[i].se - mid.se);
	}
	cout << res << '\n';
	cout << mid.fi << " " << mid.se << '\n';
	for (int i = 1; i <= n; i++) 
		cout << store[i].fi << " " << store[i].se << '\n';
	
}