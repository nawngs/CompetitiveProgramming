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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

pll a[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	// for (int i = 1; i <= n; i++) cerr << a[i].fi << " " << a[i].se << '\n';
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll minh = -INF, maxl = INF; 
		for (int j = i + 1; j <= n; j++) {
			if (minh > a[j].se && a[j].se > maxl) {
				// cout << i << " " << j << " " << minh << " " << maxl << '\n';
				res = (res + (a[j].fi - a[i].fi - 1) * (minh - maxl - 1)) % MOD;
			}
			if (a[j].se >= a[i].se) {
				if (minh == -INF) minh = a[j].se;
				else minh = min(minh, a[j].se);
			}
			if (a[j].se <= a[i].se) {
				if (maxl == INF) maxl = a[j].se;
				else maxl = max(maxl, a[j].se);
			}
		}
	}
	cout << res;
}