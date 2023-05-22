#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, h, dp[2003][2003], a[2003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > h) {
			cout << 0 << '\n';
			return 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		ll v1 = (h > a[i] ? dp[i - 1][h - a[i] - 1] : 0), v2 = dp[i - 1][h - a[i]];
		dp[i][h - a[i]] = v1; // mo tai i
		if (h > a[i]) dp[i][h - a[i] - 1] = (v1 * (h - a[i])) % MOD; // mo va dong tai i
		dp[i][h - a[i]] = (dp[i][h - a[i]] + v2) % MOD; //ko dong tai i
		if (h > a[i]) dp[i][h - a[i] - 1] = (dp[i][h - a[i] - 1] + v2 * (h - a[i])) % MOD; // dong tai i
	}	
	cout << dp[n][0];
}