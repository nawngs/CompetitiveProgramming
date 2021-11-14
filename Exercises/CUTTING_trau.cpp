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

const string NAME = "CUTTING";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[100005], dp[100005];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = INF;
	}
	
	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] == INF) {
			cout << -1 << '\n';
			return ;
		}
 		ll tam = 0;
		ll sum = 0;
		for (int j = i; j <= n; j++) {
			sum += a[j];
			tam = max(tam, a[j]);
			if (sum > m) break;
			dp[j] = min(dp[j], dp[i - 1] + tam);
		}
	}
	cout << dp[n] << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
