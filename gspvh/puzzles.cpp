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

const string NAME = "puzzles";
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

int dp[26][26], n, ans = 0;

string s;

int main() {
	fast;
	fre();
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) dp[i][j] = -INF;
		dp[i][i] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < 26; j++) 
			dp[j][s[s.size() - 1] - 'a'] = max(dp[j][s[s.size() - 1] - 'a'], dp[j][s[0] - 'a'] + (int)s.size());
		ans = max(ans, dp[s[s.size() - 1] - 'a'][s[s.size() - 1] - 'a']);
		
	}
	cout << ans;
}
