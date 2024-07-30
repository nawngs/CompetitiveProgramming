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
const int N = 1E4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, x;

pii a[N + 3];

int f[N + 3], lst[N + 3], g[N + 3];

bool check(int md) {
	ll rem = 0;
	for (int i = 1; i <= n; i++) {
		if (lst[i] > md) return false;
		rem += min(g[i], (md - lst[i]) / x);
	}
	// cout << g[n] << '\n';
	return f[m] - rem <= k;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	set < pll > ms;
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		ll cur = a[i].fi;
		int temp = 1;
		for (int j = 1; j <= m; j++) {
			cur += a[i].se;
			int val = cur / x;
			g[i] += val;
			while (val > 0) {
				if (temp == m) f[temp] += val, val = 0;
				else {
					if (val >= k - f[temp]) {
						val = val - k + f[temp];
						f[temp] = k;
						temp ++;
					}
					else {
						f[temp] += val;
						val = 0;
					}
				}
			}
			cur %= x;
		}
		lst[i] = cur;
		// cout << i << " " << lst[i] << " " << g[i] << '\n';
	}
	for (int i =1 ; i <= m; i++) cout << f[i] << '\n';
	 cout << check(17);
	// int l = 1, r = INF, mid, ans;
	// while (l <= r) {
		// mid = (l + r) / 2;
		// if (check(mid)) {
			// ans = mid;
			// r = mid - 1;
		// }
		// else l = mid + 1;
	// }
	// cout << ans;
}