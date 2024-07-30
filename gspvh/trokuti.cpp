#include <bits/stdc++.h>

#define name "trokuti"
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
const int N = 3E5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n;

pll a[N + 3];	

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> a[i].fi >> a[i].se >> x;
	}
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return x.fi * y.se < x.se * y.fi;
	});
	ll res = n * (n - 1) * (n - 2) / 6;
	res %= MOD;
	ll cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].fi * a[i - 1].se == a[i].se * a[i - 1].fi) cnt ++;
		else {
			ll temp = cnt * (cnt - 1) / 2;
			temp = (temp * (n - 2)) % MOD;
			res = (res - temp + MOD) % MOD;
			temp = cnt * (cnt - 1) * (cnt - 2) / 3;
			temp %= MOD;
			res = (res + temp) % MOD;
			cnt = 1;
		}
	}
	ll temp = cnt * (cnt - 1) / 2;
	temp = (temp * (n - 2)) % MOD;
	res = (res - temp + MOD) % MOD;
	temp = cnt * (cnt - 1) * (cnt - 2) / 3;
	temp %= MOD;
	res = (res + temp) % MOD;
	cout << res;
}