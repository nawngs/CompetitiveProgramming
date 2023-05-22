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

int n, s1[303][303][303], s2[303][303][303], dp[303][303][303];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	dp[2][1][2] = 1;
	for (int i = 2; i < n; i++) {
		for (int l = 1; l < n; l++)
		for (int r = l + 1; r <= n; r++) {
			if (dp[i][l][r] == 0) continue;
			int val = dp[i][l][r];
			add(s1[i + 1][l + 1][r + 1], val); add(s1[i + 1][r + 1][r + 1], -val);
			add(s2[i + 1][l][l + 1], val); add(s2[i + 1][l][r + 1], -val);
		}
		for (int r = 1; r <= i + 1; r++)
			for (int l = 1; l < r; l++) 
				add(s1[i + 1][l][r], s1[i + 1][l - 1][r]);
		for (int l = 1; l < i + 1; l++)
			for (int r = l + 1; r <= i + 1; r++)
				add(s2[i + 1][l][r], s2[i + 1][l][r - 1]);
		for (int l = 1; l < i + 1; l++)
			for (int r = l + 1; r <= i + 1; r++) {
				add(dp[i + 1][l][r], s1[i + 1][l][r]); add(dp[i + 1][l][r], s2[i + 1][l][r]);
				if (l == 1) add(dp[i + 1][l][r + 1], dp[i][l][r]);
				if (r == i) add(dp[i + 1][l][r + 1], dp[i][l][r]);
			}
	}
	int ans = 0;
	for (int l = 1; l < n; l++)
		for (int r = l + 1; r <= n; r++) add(ans, dp[n][l][r]);
	cout << ans;

}