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

const string NAME = "plgame";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

bool dp[1003][1003][5][5];

string s[5];

void sol() {
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	memset(dp, false, sizeof(dp));
	int ans = 1;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i ++) {
			int j = i + k - 1;
			if (k == 1) for (int p = 1; p <= 3; p++) dp[i][j][p][p] = true;
			if (k == 2) {
				for (int p = 1; p <= 3; p++) {
					for (int q = 1; q <= 3; q++) {
						if (abs(p - q) > 1) dp[i][j][p][q] = false;
						else dp[i][j][p][q] = (s[p][i] == s[q][j] ? true : false);
					}
				}
			}
			if (k >= 3) {
				for (int p = 1; p <= 3; p++) {
					for (int q = 1; q <= 3; q++) {
						if (s[p][i] != s[q][j]) {
							dp[i][j][p][q] = false;
							continue;
						}
						for (int pp = 1; pp <= 3; pp++) {
							if (abs(pp - p) > 1) continue;
							for (int qq = 1; qq <= 3; qq++) {
								if (abs(qq - q) > 1) continue;
								dp[i][j][p][q] = (dp[i][j][p][q] || dp[i + 1][j - 1][pp][qq]);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			for (int p = 1; p <= 3; p++)
				for (int q = 1; q <= 3; q++) ans = max(ans, (dp[i][j][p][q] ? j - i + 1 : 0));
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
