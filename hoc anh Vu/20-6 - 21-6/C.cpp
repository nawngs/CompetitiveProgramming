#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n;

pll a[100003];

bool check(ll x) {
	for (int i = 1; i <= n; i++) {
		x -= a[i].fi;
		if (x < 0) return false;
		x += a[i].se;
	}
	return true;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	sort(a + 1, a + n + 1, [](pll &x, pll &y) {
		if (x.se - x.fi > 0 && y.se - y.fi < 0) return true;
		if (x.se - x.fi < 0 && y.se - y.fi > 0) return false;
		if (x.se - x.fi > 0 && y.se - y.fi > 0) return (x.fi < y.fi);
		return (x.fi > y.fi);
	});
	ll l = 1, r = 1e18, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}
