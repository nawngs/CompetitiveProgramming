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

int n, a[2003], x;

bool dp[2003][5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[n + 1][0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i + 1][j];
			if (j >= a[i]) dp[i][j] |= dp[i + 1][j - a[i]]; 
		}
	}
	a[n + 1] = INF;
	int cur = 0, res = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (cur >= x) break;
		for (int j = max(cur, x - a[i] + 1); j <= x; j++) {
			if (dp[i][j - cur]) {	
				//if (x - j == 1) cout << i << " " << j - cur << '\n';
				res = max(res, x - j);
				break;
			}
		}
		cur += a[i];
	}
	cout << res;
}