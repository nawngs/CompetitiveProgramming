#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define run() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, a[100005], dp[100005][3];

int main() {
	run();
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	ll sum0 = 1, sum1 = 0;
	FOR(i, 1, n) {
		if (a[i] % 2 == 0) {
			sum0 += sum0;
			sum1 += sum1;
			sum0 %= MOD;
			sum1 %= MOD;
		}
		else {
			ll tam = sum0;
			sum0 += sum1;
			sum1 += tam;
			sum0 %= MOD;
			sum1 %= MOD;
		}
	}
	cout << sum0 - 1;
}
