#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, a[45];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == a[j]) continue;
			if (ans == -1) ans = abs(a[i] - a[j]);
			else ans = __gcd(ans, abs(a[i] - a[j]));
		}
	}
	cout << ans << '\n';
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
