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

const string NAME = "listab";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int a[1000003], dp[1000003];

int n, m;

vector < pii > val;

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[(i - 1) * m + j];
			val.push_back({i, j});
		}
	sort(val.begin(), val.end(), [&](pii &x, pii &y) {
		return a[(x.fi - 1) * m + x.se] < a[(y.fi - 1) * m + y.se];
	});
	bool th = false;
	for (auto x : val) {
		th |= (x.fi == 1 && x.se == 1);
		if (!th) continue;
		int pos = (x.fi - 1) * m + x.se;
		dp[pos] = 1;
		if (x.se > 1) dp[pos] = max(dp[pos], dp[pos - 1] + 1);
		if (x.se < m) dp[pos] = max(dp[pos], dp[pos + 1] + 1);
		if (x.fi > 1) dp[pos] = max(dp[pos], dp[pos - m] + 1);
		if (x.fi < n) dp[pos] = max(dp[pos], dp[pos + m] + 1);
 	}
 	cout << dp[n * m];
}