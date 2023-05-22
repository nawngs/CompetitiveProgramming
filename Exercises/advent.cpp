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

const string NAME = "advent";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
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

ll n, d, dp[2003][2003];

pll a[2003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return (x.fi + x.se < y.fi + y.se) || (x.fi + x.se == y.fi + y.se && x.fi < y.fi);
	});
	cin >> d;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) dp[i][j] = -LINF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) 
		dp[0][0] += a[i].fi;
	for (int i = 1; i <= n; i++) {
		//cout << a[i].fi << " " << a[i].se << '\n';
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (dp[i - 1][j - 1] + a[i].se >= d) 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - a[i].fi);	
		}
	}
	for (int i = n; i >= 0; i--)
		if (dp[n][i] >= 0) {
			cout << i << '\n';
			return 0;
		}
}
