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

ll n, a[100005], k;

int main() {
	fastflow;
	cin >> n >> k;
	ll sum;
	cin >> sum;
	n --;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater < int >());
	for (int i = 1; i <= n; i++) {
		if (i <= k) sum += a[i];
		else sum -= a[i];
	}
	cout << sum;
}
