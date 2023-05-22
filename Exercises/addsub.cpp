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

const string NAME = "addsub";
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

ll n, k, a[20003], sum = 0;

bool th = false;

bool dp[20003][24];

void back_track(ll pos) {
	if (th) return;	
	if (pos == n) {
		if (sum % k == 0) th = true;
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 1) sum -= a[pos + 1];
		else sum += a[pos + 1];
		back_track(pos + 1);
		if (th) return;
		if (i == 1) sum += a[pos + 1];
		else sum -= a[pos + 1]; 
	}

}

void sol1() {
	sum = a[1];
	th = false;
	back_track(1);
	cout << th << '\n';
}

void sol2() {
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < k; j++) dp[i][j] = false;
	dp[1][a[1]] = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = (dp[i - 1][(j + a[i]) % k] || dp[i - 1][(j - a[i] + k) % k]);
		}
	}
	cout << dp[n][0] << '\n';
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	if (n <= 20) sol1();
	else sol2();
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
