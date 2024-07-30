#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define plli pair < pll, int >
#define fi first
#define se second

using namespace std;

const int NMAX = 1E5;

int n, k, a[NMAX + 3], s[NMAX + 3];

ll dp[NMAX + 3][2];

int trace[NMAX + 3][203];

using Line = plli;

Line lines[NMAX + 3];

int top = 0;

ll get(Line a, ll x) {
	return a.fi.fi * x + a.fi.se;
}

bool bad(Line a, Line b, Line c) {
	return (double)(a.fi.se - b.fi.se) / (a.fi.fi - b.fi.fi) >= (double)(a.fi.se - c.fi.se) / (a.fi.fi - c.fi.fi);
}

void Insert(Line newline) {
	int l = 0, r = top - 1, mid, ans = top;
	while (l <= r) {
		mid = (l + r) / 2;
		if (bad(lines[mid - 1], lines[mid], newline)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	lines[ans] = newline; top = ans + 1;
}

pll query(ll x) {
	ll l = 0, r = top - 1, mid;
	pll ans = {get(lines[l], x), lines[l].se};
	while (l < r) {
		mid = (l + r) / 2;
		pll v1 = {get(lines[mid], x), lines[mid].se}, v2 = {get(lines[mid + 1], x), lines[mid + 1].se};
		if (v1 < v2) l = mid + 1;
		else r = mid;
		ans = max({ans, v1, v2});
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= k; i++) {
		top = 0;
		Insert({{-s[i - 1], dp[i - 1][(i & 1) ^ 1]}, i - 1});
		for (int j = i; j <= n; j++) {
			pll temp = query(s[n] - s[j]);
			temp.fi += 1ll * s[j] * (s[n] - s[j]);
			dp[j][i & 1] = temp.fi; trace[j][i] = temp.se;
			cout << j << " " << i << " " << dp[j][i & 1] << '\n';
			Insert({{-s[j], dp[j][(i & 1) ^ 1]}, j});
		}
	}
	int pos = -1;
	for (int i = 1; i <= n; i++) if (pos == -1 || dp[i][k & 1] > dp[pos][k & 1]) pos = i;
	cout << dp[pos][k & 1] << '\n';
	// for (int i = k; i >= 1; i--) {
		// cout << pos << " ";
		// pos = trace[pos][i];
	// }
}