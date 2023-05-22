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

int n;

pair < pii, pii > a[2003];

vector < pair < pii, pii > > b;

bool check(pair < pii, pii > x, pii y) {
	int disx = abs(x.fi.fi - x.se.fi), disy = abs(x.fi.se - x.se.se);
	int temp = __gcd(disx, disy);
	int lenx = disx / temp, leny = disy / temp;
	if (abs(y.fi - x.fi.fi) % lenx != 0) return false;
	if (abs(y.se - x.fi.se) % leny != 0) return false;
	return true;
}

void sol() {
	cin >> n;
	ll res = 0;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
	b.clear();
	for (int i = 1; i <= n; i++) {
		bool th = 1;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			if (min(a[j].fi.fi, a[j].se.fi) <= a[i].fi.fi && a[i].fi.fi <= max(a[j].fi.fi, a[j].se.fi)
			 && min(a[j].fi.fi, a[j].se.fi) <= a[i].se.fi && a[i].se.fi <= max(a[j].fi.fi, a[j].se.fi)
			 && min(a[j].fi.se, a[j].se.se) <= a[i].fi.se && a[i].fi.se <= max(a[j].fi.se, a[j].se.se)
			 && min(a[j].se.fi, a[j].se.se) <= a[i].se.se && a[i].se.se <= max(a[j].fi.se, a[j].se.se)) {
				if (!check(a[i], a[j].fi) || !check(a[i], a[j].se)) {
					th = false;
					break;
				}
			}
		}
		if (th) b.push_back(a[i]);
	}
			
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int O; cin >> O;
	int t; cin >> t; while (t --) sol();
}