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
const ll LINF = 2E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

pll a[300003];

vector < pair < pll, pll > > temp;

bool check(ll x) {
	temp.clear();
	for (int i = 1; i <= n; i++) {
		pll temp1, temp2;
		temp1 = {a[i].fi - x, a[i].se};
		temp2 = {a[i].fi + x, a[i].se};
		temp.push_back(mp(temp1, temp2));
	}
	for (auto &x : temp) {
		x.fi = mp(x.fi.fi - x.fi.se, x.fi.fi + x.fi.se);
		x.se = mp(x.se.fi - x.se.se, x.se.fi + x.se.se);
	}
	ll maxx = -LINF, maxy = -LINF, minx = LINF, miny = LINF;
	for (auto x : temp) {
		maxx = max(maxx, x.fi.fi);
		maxy = max(maxy, x.fi.se);
		minx = min(minx, x.se.fi);
		miny = min(miny, x.se.se);
	}
	return (maxx <= minx && maxy <= miny);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	ll l = 0, r = LINF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}