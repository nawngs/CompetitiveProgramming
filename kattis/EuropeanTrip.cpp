#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define pld pair < ld, ld >
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
const ld pi = acos(-1);
const ld angle = 2 * pi / 100;
const ld Cos = cos(angle);
const ld Sin = sin(angle);

using Point = pld;

Point A[3], House = {0, 0};

ld R = 2000;

ld best = LINF;

ld calc(Point X) {
	ld res = 0;
	for (int i = 0; i < 3; i++) 
		res += sqrtl((X.fi - A[i].fi) * (X.fi - A[i].fi) + (X.se - A[i].se) * (X.se - A[i].se))	;
	return res;
}

bool minimize(ld &x, const ld &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

void local_search() {
	Point cur = {House.fi + R, House.se}, pos = House;
	for (int i = 0; i <= 100; i++) {
		if (minimize(best, calc(cur))) pos = cur;
		Point nxt;
		nxt.fi = House.fi + (cur.fi - House.fi) * Cos - (cur.se - House.se) * Sin;
		nxt.se = House.se + (cur.fi - House.fi) * Sin + (cur.se - House.se) * Cos;
		cur = nxt;
	}
	House = pos;
	R -= R / 100;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 0; i < 3; i++) cin >> A[i].fi >> A[i].se;
	best = calc(House);
	for (int i = 1; i <= 2000; i++) local_search();
	cout << fixed << setprecision(9) << House.fi << " " << House.se << '\n';
}