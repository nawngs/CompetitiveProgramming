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

const string NAME = "bookcase";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct book {
	int h, t;
} a[73];

int n, dp[2103][2103];

void sol() {
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) cin >> a[i].h >> a[i].t;
	sort(a + 1, a + n + 1, [](book &x, book &y) {
		return x.h > y.h;
	});
	for (int i = 1; i <= n; i++) s += a[i].t;
	for (int i = 0; i <= s; i++) 
		for (int j = 0; j <= s; j++) dp[i][j] = INF;
	dp[0][0] = 0;
	ll ans = INF;
	for (int i = 2; i <= n; i++) {
		for (int x = s; x >= 0; x--) {
			for (int y = s; y >= 0; y--) {
				if (x == a[i].t) dp[x][y] = min(dp[x][y], a[i].h + dp[0][y]);
				if (x > a[i].t) dp[x][y] = min(dp[x][y], dp[x - a[i].t][y]);
				if (y == a[i].t) dp[x][y] = min(dp[x][y], a[i].h + dp[x][0]);
				if (y > a[i].t) dp[x][y] = min(dp[x][y], dp[x][y - a[i].t]);
				if (x != 0 && y != 0) ans = min(ans, 1ll * (a[1].h + dp[x][y]) * max(x, max(y, s - x - y)));
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
