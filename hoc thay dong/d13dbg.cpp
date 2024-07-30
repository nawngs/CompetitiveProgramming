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

const string NAME = "dbg";
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

struct Food {
	int t, w;
} a[1003];

int n, A, B, D, dp[1003][10003];

int main() {
	fast;
	//fre();
	cin >> n >> A >> B >> D;
	for (int i = 1; i <= n; i++) cin >> a[i].t >> a[i].w;
	sort(a + 1, a + n + 1, [&](Food &x, Food &y) {
		return x.w * y.t > y.w * x.t;
	});
	for (int i = 1; i <= n; i++) 
		for (int j = A; j <= B; j++) dp[i][j] = INF;
	int s = 0;	
	for (int i = 1; i <= n; i++) {
		s += a[i].t;
		for (int j = A; j <= B; j++) {
			if (j - a[i].t >= A) 
				dp[i][j - a[i].t] = min(dp[i][j - a[i].t], dp[i - 1][j] + abs(D - j) * a[i].w);
			if (j + s <= B) dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(j + s - D) * a[i].w);
		}
	}
	int ans = INF;
	for (int j = A; j <= B; j++) ans = min(ans, dp[n][j]);
	cout << ans;
}
