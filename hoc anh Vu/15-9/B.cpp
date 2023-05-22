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

string x, y[33];

bitset < 253 > dp[253][33][22], f[253];

int n, res[253];

int main() {
	fast;
	cin >> x >> n;
	for (int i = 1; i <= n; i++) cin >> y[i];
	for (int i = x.size() - 1; i >= 0; i--) {
		for (int k = 1; k <= n; k++) dp[i][k][0][i] = 1;
		for (int j = i; j < x.size(); j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 0; l < y[k].size(); l++) {
					if (dp[i][k][l][j]) {
						dp[i][k][l] |= f[j];
						if (x[j] == y[k][l]) dp[i][k][l + 1][j + 1] = 1;
					}
				}
			}
			for (int k = 1; k <= n; k++) if (dp[i][k][y[k].size()][j]) f[i][j] = 1;
		}
	for (int k = 1; k <= n; k++) if (dp[i][k][y[k].size()][x.size()]) f[i][x.size()] = 1;
	}
	for (int i = 1; i <= x.size(); i++) {
		res[i] = res[i - 1] + 1;
		for (int j = i - 1; j >= 0; j--) if (f[j][i]) res[i] = min(res[i], res[j]);
	}
	cout << res[x.size()];
}
