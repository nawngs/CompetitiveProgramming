#include <bits/stdc++.h>

#define int ll
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

ll n, k, a[N + 3], b[N + 3];

ll res;

vector < ll > c;

bool check(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) continue;
		ll temp = (a[i] - x) / b[i] + ((a[i] - x) % b[i] != 0);
		cnt += temp;
	}
	return (cnt >= k);
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll l = 0, r = INF, mid, ans = 0;
	res = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	c.clear();
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= ans) continue;
		ll temp = (a[i] - ans) / b[i] + ((a[i] - ans) % b[i] != 0);
		cnt += temp;
		res += a[i] * temp - temp * (temp - 1) / 2 * b[i];
		c.pb(a[i] - (temp - 1) * b[i]);
	}
	sort(c.begin(), c.end(), greater<ll>());
	while (cnt > k) {
		res -= c.back();
		c.pop_back();
		cnt --;
	}
	cout << res << '\n';
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}