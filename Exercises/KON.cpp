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
const int BLOCK_SIZE = 300;

int n, q;

int res[100003], dp[100003][BLOCK_SIZE + 2];

int main() {
	fast;
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		int a, l, d;
		cin >> a >> l >> d;
		if (d > BLOCK_SIZE) for (int j = 0; j < l; j++) res[a + j * d] ++;
		else {
			dp[a][d] ++;
			if (a + d * l <= n) dp[a + d * l][d] --;
		}
	}
	for (int j = 1; j <= BLOCK_SIZE; j++)
		for (int i = j + 1; i <= n; i++) dp[i][j] += dp[i - j][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= BLOCK_SIZE; j++) res[i] += dp[i][j];
		cout << res[i] << ' ';
	}
	return 0;
}
