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

int n, dp[100003][2];

pii a[100003];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][1];
		dp[i][0] = 0;
	}
	for (int i = 1; i < n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = n - 1; i > 0; i--) {
		if (a[i].se == 0) {
			dp[a[i].fi][1] += dp[i][0];
			dp[a[i].fi][0] += max(dp[i][1], dp[i][0]);
		}
		if (a[i].se == 1) {
			dp[a[i].fi][1] = max(dp[a[i].fi][1] + max(dp[i][1], dp[i][0]), dp[i][1] + max(dp[a[i].fi][1], dp[a[i].fi][0]));
			dp[a[i].fi][0] = dp[a[i].fi][0] + dp[i][0];
		}
		if (a[i].se == 2) {
			dp[a[i].fi][1] = max(dp[a[i].fi][1] + dp[i][0], dp[i][1] + dp[a[i].fi][0]);
			dp[a[i].fi][0] = dp[a[i].fi][0] + dp[i][0];
		}
	}
	cout << max(dp[0][1], dp[0][0]);
}
