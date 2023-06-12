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

int s, p;

bitset < 8101 > dp[101][902];

void sol() {
	cin >> s >> p;
	if (s > 900 || p > 8100) {
		cout << "No solution" << '\n';	
		return ;
	}
	if (!dp[0][s][p]) {
		cout << "No solution" << '\n';	
		return ;
	}
	int j = s, k = p;
	bool has1 = 0;
	for (int i = 0; i < 100; i++) {
		for (int dg = 0; dg <= 9; dg++) {
			if (dp[i + 1][j - dg][k - dg * dg]) {
				if (dg == 0 && has1) cout << dg;
				if (dg != 0) cout << dg;
				has1 |= (dg != 0);  
				j -= dg;
				k -= dg * dg;
				break;
			}
		}
	}
	cout << '\n';
}

int main() {
	fast;
	//fre();
	dp[100][0][0] = 1;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j <= 900; j++) dp[i][j] = 0;
	for (int i = 0; i <= 9; i++) 
		if (i <= 900 && i * i <= 8100) dp[99][i][i * i] = 1;
	for (int i = 98; i >= 0; i--) {
		for (int j = 0; j <= 900; j++) {
			for (int dg = 0; dg <= 9; dg++) {
				if (j - dg > 900 || dg * dg > 8100) break;
				dp[i][j] |= (dp[i + 1][j - dg] << (dg * dg));
			}
		}
	}
	int t = 1;
	cin >> t;
	while (t --) sol();
}
