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

const string NAME = "brentford40mu";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string a, b;

pll dp[1000003][4];

void add(pll &x, pll y, int dga, int dgb) {
	x.fi = (x.fi + y.fi) % MOD;
	ll sum = 0;
	sum = y.se * 10 + y.fi * (dga + dgb);
	sum %= MOD;
	x.se += sum;
	x.se %= MOD;
}

int main() {
	fast;
	//fre();
	cin >> a >> b;
	int n = a.size();
	a = ' ' + a;
	b = ' ' + b;
	dp[0][0] = {1, 0};
	for (int i = 1; i <= n; i++) {
		for (int dga = 0; dga <= 9; dga++) {
			if (a[i] != '?' && a[i] - '0' != dga) continue;
			for (int dgb = 0; dgb <= 9; dgb++) {
				if (b[i] != '?' && b[i] - '0' != dgb) continue;
				if (dga == dgb) {
					add(dp[i][0], dp[i - 1][0], dga, dgb);
					add(dp[i][1], dp[i - 1][1], dga, dgb);
					add(dp[i][2], dp[i - 1][2], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
				}
				if (dga > dgb) {
					add(dp[i][1], dp[i - 1][1], dga, dgb);
					add(dp[i][1], dp[i - 1][0], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
					add(dp[i][3], dp[i - 1][2], dga, dgb);
				}
				if (dgb > dga) {
					add(dp[i][2], dp[i - 1][2], dga, dgb);
					add(dp[i][2], dp[i - 1][0], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
					add(dp[i][3], dp[i - 1][1], dga, dgb);
				}
			}
		}
	}
	cout << dp[n][3].se << '\n';
}