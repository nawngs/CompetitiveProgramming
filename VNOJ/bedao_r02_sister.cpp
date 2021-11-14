#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, a[22], sum1 = 0, sum2 = 0, ans = -1;

bool f[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = true;
	f[1] = f[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i]) for (int j = i * i; j <= nmax; j += i) f[j] = false;
}

void backtrack(int pos) {
	if (pos == n + 1) {
		if (f[abs(sum1 - sum2)]) ans = max(ans, abs(sum1 - sum2));
		return ;
	}
	for (int i = 1; i <= 2; i++) {
		if (i == 1) sum1 += a[pos];
		if (i == 2) sum2 += a[pos];
		backtrack(pos + 1);
		if (i == 1) sum1 -= a[pos];
		if (i == 2) sum2 -= a[pos];
	}
}

int main() {
	slow;
	sang();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	backtrack(1);
	cout << ans;
}
