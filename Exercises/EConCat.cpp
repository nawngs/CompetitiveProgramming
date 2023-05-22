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

const string NAME = "econcat";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s, x[103];

int n, a[103], dp[103][103];

int solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l > r) {
		dp[l][r] = 0;
		return 0;
	}
	int res = 0;
	string tam = "";
	for (int i = l - 1; i <= r; i++) {
		if (i != l - 1) tam += s[i];
		string temp = "";
		for (int j = r + 1; j > i; j--) {
			if (j != r + 1) temp = s[j] + temp;
			string str = tam + temp;
			for (int k = 1; k <= n; k++) if (str == x[k]) res = max(res, a[k] + solve(i + 1, j - 1));
		} 
	}
	dp[l][r] = res;
	//cout << l << " " << r << " " << res << '\n';
	return dp[l][r];
}

void sol() {
	cin >> s >> n;
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve(0, s.size() - 1);
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
