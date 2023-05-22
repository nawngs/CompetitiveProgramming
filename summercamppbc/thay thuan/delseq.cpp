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

int n, a[1003], dp[1003][1003], s[1003];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 1000; j++)  dp[i][j] = -INF;
	dp[0][0] = 0;
	int res = -INF;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], 0) + a[i];
		//cout << i << " " << 0 << " " << dp[i][0] << '\n';
		for (int bit = 1; bit <= i; bit++) {
			dp[i][bit] = max(dp[i][bit], max(0, dp[i - 1][bit]) + a[i]);
			for (int pos = 0; (1 << pos <= i); pos++) if (getbit(bit, pos)) dp[i][bit] = max(dp[i][bit], dp[i - (1 << pos)][bit - (1 << pos)]);
			//cout << i << " " << bit << " " << dp[i][bit] << '\n';
			res = max(res, dp[i][bit]);
		}
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
