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

int n, it[1600003];

pii a[200003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		val.pb(a[i].fi), val.pb(a[i].se);
	}
	sort(val.begin(), val.end());
	val.erase(unque(val.begin(), val.end()));
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(val.begin(), val.end(), a[i].fi) - val.begin();
		a[i].se = lower_bound(val.begin(), val.end(), a[i].se) - val.begin();
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		
	}
}