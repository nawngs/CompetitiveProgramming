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

vector < int > st[2 * NMAX + 3];

int f[2 * NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	int res = 0;
	vector < int > compress;
	for (int i = 0; i < n; i++) {
		cin >> a[i].fi >> a[i].se;
		compress.pb(a[i].fi), compress.pb(a[i].se);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	for (int i = 0; i < n; i++) {
		a[i].fi = lower_bound(compress.begin(), compress.end(), a[i].fi) - compress.begin();
		a[i].se = lower_bound(compress.begin(), compress.end(), a[i].se) - compress.begin();
	}
	for (int i = 0; i < n; i++) {
		if (a[i].fi >= a[i].se) res ++, st[a[i].se].pb(a[i].fi);
		else {
			f[a[i].fi] --;
			f[a[i].se] ++;
		}
	}
	int cur = 0;
	priority_queue < int > heap;
	for (int i = 0; i < compress.size(); i++) {
		for (auto v : st[i]) heap.push(v);
		cur += f[i];
		//cout << x.fi << " " << cur << '\n';
		while (cur < 0) {
			if (!heap.size() || heap.top() <= i) {
				cout << -1;
				return 0;
			}
			res --;
			cur ++; f[heap.top()] --;
			heap.pop();
		}
	}
	cout << res;
}