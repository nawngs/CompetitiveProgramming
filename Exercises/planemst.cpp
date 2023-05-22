#include <bits/stdc++.h>

#define name "planemst"
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

struct Data {
	ll v;
	ll id;
} a[200003];

ll w, h, res = 0;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> w >> h;
	for (int i = 1; i <= w; i++) {
		cin >> a[i].v;
		a[i].id = 0;
	}
	for (int i = 1; i <= h; i++) {
		cin >> a[i + w].v;
		a[i + w].id = 1;
	}
	sort(a + 1, a + w + h + 1, [&](Data &x, Data &y) {
		return x.v < y.v;
	});
	ll res = 0, cntx = 0, cnty = 0;
	for (int i = 1; i <= w + h; i++) {
		if (!a[i].id) {
			res += a[i].v * (h - cnty + 1);
			cntx ++;
		}
		else {
			res += a[i].v * (w - cntx + 1);
			cnty ++;
		}
	}
	cout << res;
}