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

int nxt[200003][30], dp[200005]; 

string s;

int main() {
	fast;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	dp[n + 1] = 1, dp[n + 2] = 0;
	for (int i = 0; i <= 'z' - 'a'; i++) nxt[n + 1][i] = n + 1;
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j <= 'z' - 'a'; j++) nxt[i][j] = nxt[i + 1][j];
		if (i != 0) nxt[i][(s[i] - 'a')] = i;
	}
	for (int i = n; i >= 0; i--) {
		dp[i] = INF;
		for (int j = 0; j <= 'z' - 'a'; j++) dp[i] = min(dp[i], dp[nxt[i][j] + 1] + 1);
	}
	int i = 0;
	while (i <= n) {
		for (int j = 0; j <= 'z' - 'a'; j++) {
			if (dp[nxt[i][j] + 1] == dp[i] - 1) {
				cout << (char) (j + 'a');
				i = nxt[i][j];
				break;
			}
		}
		i ++;
	}
}
