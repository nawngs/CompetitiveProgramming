#include <bits/stdc++.h>

#define name "262144"
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

int n, a[262145], dp[262145][105];

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		 cin >> a[i];
		 dp[i][0] = -1;
	}
	dp[n + 1][0] = -1;
	int ans = 0;
	for (int v = 1; v <= 105; v++) 
		for (int i = 1; i <= n + 1; i++) {
			dp[i][v] = -1;
			if (a[i] == v) dp[i][v] = i + 1;
			else {
				if (dp[i][v - 1] != -1 && dp[dp[i][v - 1]][v - 1] != -1) 
					dp[i][v] = dp[dp[i][v - 1]][v - 1];
			}
			if (dp[i][v] != -1) ans = max(ans, v);
		}
	cout << ans;
}