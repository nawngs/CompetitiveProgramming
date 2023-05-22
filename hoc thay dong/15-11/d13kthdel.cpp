#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ld ESP = 1e-9;
const ll INF = 1e18;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k;

vector < ll > a;

vector < pll > Lcm;

bool check(ll val) {
	ll res = 0;
	for (auto x : Lcm) {
		if (x.fi > val) continue;
		if (x.se % 2 == 1) res += val / x.fi;
		else res -= val / x.fi;
		//cout << x.fi << " " << x.se << " " << res << '\n';
	}
	return (val - res) >= k;
}

void sol() {
	cin >> n >> k;
	a.clear();
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x; 
		a.push_back(x);
	}
	Lcm.clear();
	for (int i = 1; i < (1 << (int)(a.size())); i++) {
		int p = __builtin_ctz(i);
		ll cur = a[p];
		for (int bit = p + 1; bit < (int)a.size(); bit++) {
			if ((i >> bit) & 1) {
				ll temp = __gcd(cur, a[bit]);
				cur /= temp;
				if (LINF / cur < a[bit]) {
					cur = LINF + 7;
					break;
				}
				else cur *= a[bit];
			}
		}
		Lcm.push_back({cur, __builtin_popcount(i)});
	}
	//check(149);
	ll l = 1, r = LINF, mid, ans = LINF;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';

}

signed main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
