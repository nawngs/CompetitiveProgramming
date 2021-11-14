#pragma GCC optimize ("O3")
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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, dp[100005];

pll a[100005];

int bs(ll val) {
	int l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].fi + a[mid].se <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [](pll &x, pll &y) {
		return x.fi + x.se < y.fi + y.se;
	});
	for (int i = 1; i <= n; i++) {
		int tam = bs(a[i].fi - a[i].se);
		dp[i] = max(dp[i - 1], dp[tam] + 1);
	}
	cout << dp[n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
