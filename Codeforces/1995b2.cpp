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

ll n, m;

pll a[N + 3];

ll add(ll cur, ll cnt1, ll rem2) {
	return cur + min(cnt1, min(rem2, m - cur));
}

ll remove(ll cur, ll rem1, ll cnt2) {
	if (min(rem1, cnt2) >= cur - m)  return m;
	return 0;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) cerr << a[i].fi << " " << a[i].se << '\n';
	a[n + 1].fi = LINF;
	a[0].fi = -LINF;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, min(m / a[i].fi, a[i].se) * a[i].fi);
		if (a[i + 1].fi - a[i].fi == 1) {
			ll cnt1 = min(m / a[i].fi, a[i].se);
			ll cur = cnt1 * a[i].fi;
			ll cnt2 = min(a[i + 1].se, (m - cur) / a[i + 1].fi);
			cur = cur + cnt2 * a[i + 1].fi;
			if (cur == m) res = max(res, cur);
			else res = max(res, add(cur, cnt1, a[i + 1].se - cnt2));
		}
		if (a[i].fi - a[i - 1].fi == 1) {
			ll cnt2 = min(m / a[i].fi, a[i].se);
			ll cur = cnt2 * a[i].fi;
			ll cnt1 = min(a[i - 1].se, ((m - cur) / a[i - 1].fi + 1));
			cur = cur + cnt1 * a[i - 1].fi;
			if (cur < m) {
				res = max(res, cur); continue;
			}
			if (cur == m + a[i - 1].fi) res = m;
			else res = max(res, remove(cur, a[i - 1].se - cnt1, cnt2));
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}