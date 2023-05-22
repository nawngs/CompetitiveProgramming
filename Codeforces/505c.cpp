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

int cnt[30005], d, n, dp[30005][502];

int solve(int pos, int len) {
	int temp = 250 + (len - d);
	if (pos > 30000) return 0;
	if (dp[pos][temp] != -1) return dp[pos][temp];
	dp[pos][temp] = cnt[pos];
	if (len == 1) dp[pos][temp] += max(solve(pos + len, len), solve(pos + len + 1, len + 1));
	else dp[pos][temp] += max(solve(pos + len, len), max(solve(pos + len + 1, len + 1), solve(pos + len - 1, len - 1)));
	return dp[pos][temp];
}

void sol() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x] ++;
	}
	memset(dp, 255, sizeof(dp));
	cout << solve(d, d);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
