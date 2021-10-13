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

ll n;

int main() {
	//fastflow;
	cin >> n;
	ll ans = 0;
	ll i = 1;
	while(i * i <= n) {
		//cout << i << " " << (n - i) / 2 + 1 << '\n';
		ll tamn = n / i;
		ans += (tamn - i) / 2 + 1;
		ans %= MOD;
		i ++;
	}
	cout << ans;
}
