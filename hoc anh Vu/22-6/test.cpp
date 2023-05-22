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

const string NAME = "K";
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

ll n, m;

pll a[100003];

bool check(ll x) {
	
}

int main() {
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return (x.se < y.se);
	});
	for (int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
	cout << check(78) << '\n';
	/*ll l = 0, r = 1e14, mid, res;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}	
	cout << res;
	*/
}
