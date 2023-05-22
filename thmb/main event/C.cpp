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

ll a, b;

pll dp[12];

pll res;

void solve(int x) {
	vector < int > digit;
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	reverse(digit.begin(), digit.end());
	for (int i = 0; i < digit.size(); i++) {
		dp[i] = {1, 1};
		for (int j = 0; j < i; j++) if (digit[i] > digit[j]) {
			if (dp[i].fi < dp[j].fi + 1) {
				dp[i] = dp[j];
				dp[i].fi ++;
			}
			else if (dp[i].fi == dp[j].fi + 1) dp[i].se += dp[j].se;
		}
		if (res.fi < dp[i].fi) res = dp[i];
		else if (res.fi == dp[i].fi) res.se += dp[i].se;
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		res = {0, 0};
		cin >> a >> b;
		for (int i = a; i <= b; i++) solve(i);
		cout << "Case " << tt << ": " << res.fi << " " << res.se << '\n';
	}
	
}
