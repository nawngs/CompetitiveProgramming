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

const string NAME = "";
const ll ESP = 1e-9;
const int INF = 1e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, s, a[5005], dp[5005][5005], dem = 0;

vector < int > pos[5005];

void roi_rac() {
	pii p[5005];
	for (int i = 1; i <= n; i++) {
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1, [](pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	p[0].fi = -INF;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		pos[dem].push_back(p[i].se);
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> s;
	pos[0].push_back(s);
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= n; j++) dp[i][j] = INF;

	dp[0][s] = 0;
	int ans = INF;
	for (int i = 1; i <= dem; i++) {
		for (int j = 0; j < pos[i].size(); j++) {
			int tam = INF;
			for (auto k : pos[i - 1]) tam = min(tam, dp[i - 1][k] + min(abs(pos[i][j] - k), n - abs(pos[i][j] - k)));
			if (j - 1 >= 0) dp[i][pos[i][j - 1]] = min(dp[i][pos[i][j - 1]], tam + n - abs(pos[i][j] - pos[i][j - 1]));
			else dp[i][pos[i][pos[i].size() - 1]] = min(dp[i][pos[i].size() - 1], tam + pos[i][pos[i].size() - 1] - pos[i][j]);
			if (j + 1 < pos[i].size() - 1) dp[i][j + 1] = min(dp[i][pos[i][j + 1]], tam + n - (pos[i][j + 1] - pos[i][j]));
			else dp[i][pos[i][0]] = min(dp[i][pos[i][0]], tam + abs(pos[i][0] - pos[i][j]));
			if (i == dem) ans = min(ans, dp[i][pos[i][j]]);
		}
		for (int j = 0; j < pos[i].size(); j++) cout << i << " " << pos[i][j] << " " << dp[i][pos[i][j]] << '\n';
	}
	cout << ans;
}
