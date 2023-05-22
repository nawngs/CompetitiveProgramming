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

ll n, k, pre[103][26], dp[103][103];

string s;

void sol() {
	cin >> n >> k >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 25; j++) 
			pre[i][j] = pre[i - 1][j];
		pre[i][s[i] - 'a'] = i;
	}
	for (int i = 1; i <= n; i++) 
		dp[i][1] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 2; j <= i; j++) 
			for (int c = 0; c <= 25; c++)
				dp[i][j] += dp[pre[i - 1][c]][j - 1];
			
	ll res = 0;
	for (int i = n; i >= 1; i--) 
		for (int c = 0; c <= 25; c++) {
			int pos = pre[n][c];
			if (k > dp[pos][i]) {
				k -= dp[pos][i];
				res += dp[pos][i] * (n - i);
			}
			else {
				res += k * (n - i);
				cout << res << '\n';
				return ;
			}
		}
	if (k == 1) cout << res + n << '\n';
	else cout << -1 << '\n';
	return ;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}