#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, g1, g2, g3, dp[100003][53], num_rock = 0;

string s;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> g1 >> g2 >> g3 >> s;
	s = ' ' + s;
	for (auto c : s) {
		if (c == '#') num_rock ++;
	}
	dp[0][0] = 0;
	for (int j = 1; j <= num_rock; j++) dp[0][j] = -INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= num_rock; j++) {
			dp[i][j] = dp[i - 1][j];
			if (i > 1 && s[i] == '.' && s[i - 1] == '.') dp[i][j] = max(dp[i][j], dp[i - 2][j] + 1);
			if (i > 2 && s[i] == '.' && s[i - 1] == '#' && s[i - 2] == '.' && j > 0) 
				dp[i][j] = max(dp[i][j], dp[i - 3][j - 1]);
		}
	}
	ll res = 0;
	for (int num2 = 0; num2 <= n / 2; num2++) {
		for (int j = 0; j <= num_rock; j++) {
			ll val2 = min(1ll * num2, dp[n][j]), val1 = min(k, n - num_rock - j * 2 - 2 * val2);
			//if (val2 == 1 && j == 1) cout << val1 << '\n';
			res = max(res, val1 * g1 + val2 * g2 + j * g3);
		}
	}
	cout << res;
}