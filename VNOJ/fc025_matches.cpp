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

int n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

unsigned ll f[2005];

int main() {
	fastflow;
	cin >> n;
	f[0] = 1;
	unsigned ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i < a[j]) continue;
			if (j == 0 && i - a[j] == 0) continue;
			f[i] += f[i - a[j]];
		}
		cout << f[i] << '\n';
		ans += f[i];
	}
	cout << ans + (n >= a[0]);
}
