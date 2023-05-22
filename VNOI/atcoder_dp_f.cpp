#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < ll, pll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

string s, t;

plll dp[3005][3005];

plll maxpair (plll a, plll b, plll c) {
	if (a.fi >= b.fi && a.fi >= c.fi) return a;
	else if (b.fi >= a.fi && b.fi >= c.fi) return b;
		else return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	int ans = 0;
	pll pos;
	for (int i = 1; i < s.size(); i++) {
		for (int j = 1; j < t.size(); j++) {
			if (s[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1];
				dp[i][j].fi ++;
				dp[i][j].se.fi = i;
				dp[i][j].se.se = j;
			}
			else dp[i][j] = maxpair(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
			if (ans < dp[i][j].fi) {
				ans = dp[i][j].fi;
				pos = dp[i][j].se;
			}
		}
	}
	//cout << ans << '\n';
	string res = "";
	while (pos.fi > 0 && pos.se > 0) {
		res = s[pos.fi] + res;
		pll newpos;
		pos = dp[pos.fi - 1][pos.se - 1].se;
	}
	cout << res;
}
