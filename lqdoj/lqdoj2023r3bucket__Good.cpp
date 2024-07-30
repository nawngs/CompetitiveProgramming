#include <bits/stdc++.h>

#define name "bucket"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

pii a[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
	
	int res = -1;
	if (n <= 20) {
	 	for (int msk = 0; msk <= (1 << n); msk++) {
			bool th = true;
			vector < int > ta, tb;
			for (int i = 0; i < n; i++) {
				if (msk >> i & 1) th &= (a[i].fi >= a[i].se);
				else ta.pb(a[i].fi), tb.pb(a[i].se);
			}
			sort(ta.begin(), ta.end()); sort(tb.begin(), tb.end());
			for (int i = 0; i < SZE(ta); i++) th &= (ta[i] >= tb[i]);
			if (th) res = max(res, __builtin_popcount(msk));
		}
	}
	cout << res;
}
