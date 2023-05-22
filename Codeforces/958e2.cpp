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

ll n, k, a[500003], dp[5003][2];

pll b[500003];

vector < pll > c;

int main() {
	fast;
	//fre();
	cin >> k >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) 
		b[i] = {a[i + 1] - a[i], i};
	sort(b + 1, b + n);
	n --;
	c.push_back({-INF, INF});
	for (int i = 1; i <= min(3 * k, n); i++) 
		c.push_back({b[i].se, b[i].fi});
	sort(c.begin(), c.end());
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i < c.size(); i++) {
		//cout << c[i].fi << " " << c[i].se << '\n';
		for (int j = k; j >= 1; j--) {
			dp[j][0] = min(dp[j][0], dp[j][1]);
			if (c[i].fi - c[i - 1].fi > 1) 
				dp[j][1] = min(dp[j][1], min(dp[j - 1][0], dp[j - 1][1]) + c[i].se);
			else 
			dp[j][1] = min(dp[j][1], dp[j - 1][0] + c[i].se);;
		}w
	}
	cout << min(dp[k][0], dp[k][1]);
}
