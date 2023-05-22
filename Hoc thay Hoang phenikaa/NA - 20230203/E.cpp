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

int n, a[1000003], mx[1000003], f[1000003], dp[1003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx[i] = max(mx[i - 1], a[i]);
		f[i] = f[i - 1];
		if (mx[i] == i) f[i] = i;
	}
	dp[0] = 0;
	for (int i = 0; i < sqrt(n); i++) {
		while (dp[i] < n && mx[dp[i] + 1] == dp[i] + 1) dp[i] ++;
		for (int j = 1; i + j <= sqrt(n); j++) 
			dp[i + j] = max(dp[i + j], f[(dp[i] + (j + 1) * (j + 1) - 1 > n ? n : dp[i] + (j + 1) * (j + 1) - 1)]);
	}
	for (int i = 0; i <= sqrt(n); i++)
		if (dp[i] == n) {
			cout << i << '\n';
			return 0;
		}
}