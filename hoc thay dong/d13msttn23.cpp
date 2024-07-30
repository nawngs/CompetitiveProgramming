#include <bits/stdc++.h>


#define name ""
#define int ll
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

ll n, a[NMAX + 3], s[NMAX + 3], q;

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]);
	while (q--) {
		int t; cin >> t;
		ll res = -t * t * (n - 1);
		int l = 1, r = n, mid, ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid] <= -t) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == 0) {
			res += (a[1] + t) * (s[n] - s[1] + (n - 1) * t);
			cout << res << ' ';
		}
		else if (ans == n) {
			res += (a[n] + t) * (s[n - 1] + (n - 1) * t);
			cout << res << ' ';
		}
		else {
			res += (a[n] + t) * (s[ans] + ans * t);
			res += (a[1] + t) * (s[n - 1] - s[ans] + (n - 1 - ans) * t);
			cout << res << ' ';
		}
		
	}
}