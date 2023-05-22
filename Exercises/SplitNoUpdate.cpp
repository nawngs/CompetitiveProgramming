#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "SplitNoUpdate";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[500002], dp[500002];

bool check(int x) {
	if (a[x] < a[x - 1] && a[x - 2] < a[x - 1]) return true; // a[x - 1] la day
	if (a[x] > a[x - 1] && a[x - 2] > a[x - 1]) return true; // a[x - 1] la dinh
	return false;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (check(i)) dp[i] = max(dp[i - 1], dp[i - 2] + abs(a[i] - a[i - 1]));
		else dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
