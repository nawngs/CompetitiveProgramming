#include <bits/stdc++.h>

#define name "loan"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, m;

bool check(ll x) {
	ll g = 0, remain = k;
	while (remain > 0 && g < n) {
		ll y = (n - g) / x;
		if (y < m) {
			ll need = (n - g + m - 1) / m;
			return (need <= remain);
		}
		ll val = (n - g) - ((n - g) / x) * x;
		ll day_need = val / y + 1;
		day_need = min(day_need, remain);
		g += y * day_need;
		remain -= day_need;
	}
	return (g >= n);
}

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> k >> m;
	ll l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}