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

const string NAME = "CountTree";
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

ll n, a[100003], dp[100003], cnt[100003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[2] == 0 || a[1] != 0) {
		cout << 0 << '\n';
		return 0;
	}
	dp[0] = 1;
	cnt[0] = 1;
	ll dem = 1;
	for (int i = 3; i <= n; i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			dp[a[i - 1]] = (dp[a[i - 1] - 1] * mu(cnt[a[i - 1] - 1], dem)) % MOD;
			cnt[a[i - 1]] = dem;
			dem = 1;
		}
		//cout << i << " " << dp[a[i] - 1] << '\n';
	}
	dp[a[n]] = (dp[a[n] - 1] * mu(cnt[a[n] - 1], dem)) % MOD;
	cout << dp[a[n]];
}
