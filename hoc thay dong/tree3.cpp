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
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, w;

pll a[N + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	sort(a + 1, a + n + 1);
	ll r = 1, total = a[1].se, res = LINF;
	multiset < ll > ms;
	ms.insert(0);
	for (int i = 1; i <= n; i++) {
		while (r < n && total < w) {
			ms.insert(a[r + 1].fi - a[r].fi);
			r ++; total += a[r].se;
		}
		if (total < w) break;
		total -= a[i].se;
		res = min(res, *ms.rbegin());
		if (r > i) ms.erase(ms.find(a[i + 1].fi - a[i].fi));
	}
	cout << res;
}