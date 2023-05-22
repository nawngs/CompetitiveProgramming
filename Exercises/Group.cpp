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

const string NAME = "GROUP";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, g, c[100003], dp[1003][32], pos[100003][65], pos_val[65], f[100003][32], f2[100003][32];

bool used[65];

void sub123() {
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= g; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= g; k++) {
			memset(used, false, sizeof(used));
			int temp = 0;
			for (int j = i; j >= 1; j--) {
				temp += !used[c[j]];
				used[c[j]] = 1;
				dp[i][k] = max(dp[i][k], dp[j - 1][k - 1] + temp);
			}
		}
	}
	cout << dp[n][g] << '\n';
}

void sub4() {
	memset(pos, 255, sizeof(pos));
	memset(pos_val, 255, sizeof(pos_val));
	for (int i = 1; i <= n; i++) {
		pos[i][1] = i;
		for (int j = 2; j <= 63; j++) {
			if (pos[i - 1][j - 1] != -1 && pos_val[c[i]] < pos[i - 1][j - 1]) {
				pos[i][j] = pos[i - 1][j - 1];
				continue;
			}
			pos[i][j] = pos[i - 1][j];
			if (pos[i][j] == -1) break;
		}
		pos_val[c[i]] = i;
	}
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= g; j++) {
			f[i][j] = -INF;
			f2[i][j] = -INF;
		}
	f[0][0] = 0;
	f2[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		f2[i][0] = max(f2[i - 1][0], 0);
		for (int j = 1; j <= g; j++) {
			for (int k = 1; k <= 63; k++) {
				if (pos[i][k] == -1) break;
				f[i][j] = max(f[i][j], f2[pos[i][k] - 1][j - 1] + k);
			}
			f2[i][j] = max(f2[i - 1][j], f[i][j]);
		}

	}
	cout << f[n][g] << '\n';
}

int main() {
	fast;
	fre();
	cin >> n >> g;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 1000) sub123();
	else sub4();
}
