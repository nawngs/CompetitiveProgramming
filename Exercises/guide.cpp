#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "Guide";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, s[2005][2005], sum[2005][2005], pos;

pii a[2005];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + m + 1, [](pii &x, pii &y) {
		return (x.se < y.se);
	});
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + (max(0, min(a[j].se, i + k - 1) - max(a[j].fi, i) + 1));

	for (int i = n; i >= 1; i--) 
		for (int j = 1; j <= m; j++) sum[i][j] = max(sum[i + 1][j], s[i][m] - s[i][j - 1]);

	int ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			if (s[i][j] - s[i][0] + sum[i + 1][j + 1] > ans) {
				pos = i;
			}
			ans = max(ans, s[i][j] - s[i][0] + sum[i + 1][j + 1]);
		}

	cout << ans << '\n';
	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
