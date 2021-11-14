#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "SpecSeq";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fast_fre() {
	slow;
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[100005], k, dp[100005][3];

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
		a[i] %= 2;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][1] = INF;
	for (int i = 1; i <= k; i++) {
		int le = 0, chan = 0;
		for (int j = i; j <= n; j += k) {
			if (a[j] % 2 == 1) le ++;
			else chan ++;
		}
		dp[i][0] = min(dp[i - 1][1] + chan, dp[i - 1][0] + le);
		dp[i][1] = min(dp[i - 1][1] + le, dp[i - 1][0] + chan);
	}
	cout << dp[k][0] << '\n';
	
}

int main() {
	fast_fre();
	int t;
	cin >> t;
	while (t --) sol();
}
