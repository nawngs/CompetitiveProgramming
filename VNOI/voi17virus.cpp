#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, dp[3005][3005], q, cnt[3005];

string s;

int main() {
	fastflow;
	cin >> q >> s;
	n = s.size();
	s = ' ' + s;
	//cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (s[i] == s[j]) continue;
			int l = max(1, i - (j - i) + 1);
			int r = min(i + 1, n - 2 * (j - i) + 2);
			if (l >= r) continue;	
			dp[l][j - i] ++;
			dp[r][j - i] --;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j][i] += dp[j - 1][i];
			if (j + 2 * i - 1 > n) continue;
			cnt[dp[j][i]] = max(cnt[dp[j][i]], i);
		}
	}
	for (int i = 1; i <= n; i++) cnt[i] = max(cnt[i], cnt[i - 1]);
	while (q --) {
		int x;
		cin >> x;
		cout << cnt[x] << '\n';
	}

}	
