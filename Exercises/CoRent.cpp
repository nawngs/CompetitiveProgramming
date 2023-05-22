#include <bits/stdc++.h>

#define name "CoRent"
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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Data {
	ll c, f, v;
	bool IsCustomer;
} a[4003];

ll dp[NMAX + 3], n, m, f[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c >> a[i].f >> a[i].v;
		a[i].IsCustomer = false;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[n + i].c >> a[n + i].f >> a[n + i].v;
		a[n + i].IsCustomer = true;
	}
	sort(a + 1, a + n + m + 1, [&](Data &x, Data &y) {
		if (x.f != y.f) return x.f < y.f;
		return (x.IsCustomer == 1);
	});
	for (int j = 0; j <= m * 50; j++) 
		dp[j] = -LINF;
	dp[0] = 0;
	ll s = 0;
	for (int i = 1; i <= n + m; i++) {
		if (a[i].IsCustomer) {
			for (int j = 0; j <= s + a[i].c; j++) f[j] = -LINF;
			for (int j = s; j >= 0; j--) 
				f[j + a[i].c] = max(f[j + a[i].c], dp[j] + a[i].v);
			s += a[i].c;
			for (int j = 0; j <= s; j++) dp[j] = max(dp[j], f[j]);
		}
		else {
			for (int j = 0; j <= s; j++) f[j] = -LINF;
			for (int j = 0; j <= s; j++) 
				f[max(0ll, j - a[i].c)] = max(f[max(0ll, j - a[i].c)], dp[j] - a[i].v);
			for (int j = 0; j <= s; j++)
				dp[j] = max(dp[j], f[j]);
		}
		// cout << "//##############################################################################" << '\n';
		// cout << i << " " << a[i].c << " " << a[i].f << " " << a[i].v << '\n';
		// for (int j = 0; j <= s; j++) cout << j << " " << dp[j] << '\n';
	}
	cout << dp[0];
}