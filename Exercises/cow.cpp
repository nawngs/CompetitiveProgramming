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

const string NAME = "cow";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 2e9;
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

ll n, a, b, x[103], y[103], r[103];

ld dis(int id) {
	return (a - x[id]) * (a - x[id]) + (b - y[id]) * (b - y[id]);
}

bool check(ll len) {
	for (int i = 1; i <= n; i++) 
		if (dis(i) <= (r[i] + len) * (r[i] + len)) 
			return false;
	return 1;
}

signed main() {
	fast;
	fre();
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i] >> r[i];
	ll l = 0, r = INF, mid, ans;
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
