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

ll x, y;

ll calc(ll x, ll y) {
	if (y <= x) return x - y;
	if (y % 2 == 0) return min(y - x, 1 + calc(x, y / 2));
	return min(y - x, min(2 + calc(x, (y - 1) / 2), 2 + calc(x, (y + 1) / 2)));
}

void sol() {
	cin >> x >> y;
	cout << calc(x, y) << '\n';
}

int main() {
	fastflow;
	freopen("XY.INP", "r", stdin);
	freopen("XY.OUT", "w", stdout);	
	int t = 2;
	while (t --) sol();
}
