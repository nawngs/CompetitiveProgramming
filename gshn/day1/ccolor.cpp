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

int n, mu[5], dp[102400004], num[5];

ll a[5][40];

int calc(int x) {
	if (dp[x] != -1) return dp[x];
	int res = 0;
	int val[5];
	int temp = x;
	for (int i = n - 1; i >= 0; i--) {
		val[i] = temp / mu[i];
		temp -= val[i] * mu[i];
	}
	for (int i = 0; i < n; i++) {
		if (val[i] == num[i]) continue;
		if (a[i][val[i]] % 2 == 0) {
			int newx = x + mu[i];
			res = (res + calc(newx)) % MOD;
		}
		int nxt = (i + 1) % n;
		if (a[i][val[i]] % 2 == 1 && a[nxt][val[nxt]] % 2 == 1) {
			int newx = x + mu[i] + mu[nxt];
			res = (res + calc(newx)) % MOD;
		}
	}
	dp[x] = res;
	return res;
}

int main() {
	fast;
	cin >> n;
	mu[0] = 1;
	for (int i = 1; i < 5; i++) mu[i] = mu[i - 1] * 40;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		int id = 0;
		ll x = a[i][0];
		while (x > 0) {
			x /= 2;
			a[i][++id] = x;
		}
		num[i] = id;
		total += id * mu[i];
	}
	memset(dp, 255, sizeof(dp));
	dp[total] = 1;
	cout << calc(0);
	return 0;
}