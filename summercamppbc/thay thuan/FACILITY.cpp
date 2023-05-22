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

ll n, k, dp[1000004];

pair < pii, int > a[1000004];

int bs(int x) {
	int l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].fi.se <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> n >> k;	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		a[i].fi.se += a[i].fi.fi + k;
	}
	sort(a + 1, a + n + 1, [](pair < pii, int > &x, pair < pii, int > &y) {
		return x.fi.se < y.fi.se;
	});
	
	for (int i = 1; i <= n; i++) {
		int tam = bs(a[i].fi.fi);
		dp[i] = dp[tam] + a[i].se;
		//cout << a[i].fi.fi << " " << a[i].fi.se << " " << dp[i] << '\n';
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
