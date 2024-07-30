//[UNFINISHED]
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll h, w, k;

vector < ll > x, y;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> h >> w >> k;
	for (int i = 1; i <= k; i++) {
		int xx, yy; cin >> xx >> yy;
		x.pb(xx); y.pb(yy);
	}
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	ll lenx = x.back() - x[0] + 1, leny = y.back() - y[0] + 1, chgx = 0, chgy = 0;
	for (int i = 1; i < SZE(x); i++) if (x[i] != x[i - 1]) {
		if (lenx > x[i - 1] + h + 1 - x[i]) {
			lenx = x[i - 1] + h + 1 - x[i];
			chgx = h + 1 - x[i];
		}
		else if (lenx == x[i - 1] + h + 1 - x[i]) chgx = min(chgx, h + 1 - x[i]);
	}
	for (int i = 1; i < SZE(y); i++) if (y[i] != y[i - 1]) {
		if (leny > y[i - 1] + w + 1 - y[i]) {
			leny = y[i - 1] + w + 1 - y[i];
			chgy = w + 1 - y[i];
		}
		else if (leny == y[i - 1] + w + 1 - y[i]) chgy = min(chgy, w + 1 - y[i]);
	}
	for (int i = 0; i < SZE(x) - 1; i++) if (x[i] != x[i + 1]) {
		if (lenx > h - x[i + 1] + x[i] + 1) {
			lenx = h - x[i + 1] + x[i] + 1;
			chgx = x[i];
		}
		else if (lenx == h - x[i + 1] + x[i] + 1) chgx = min(chgx, x[i]);
	}
	for (int i = 0; i < SZE(y) - 1; i++) if (y[i] != y[i + 1]) {
		if (leny > w - y[i + 1] + y[i] + 1) {
			leny = w - y[i + 1] + y[i] + 1;
			chgy = y[i];
		}
		else if (leny == w - y[i + 1] + y[i] + 1) chgy = min(chgy, y[i]);
	}
	cout << lenx * leny << " " << chgx + chgy;
}