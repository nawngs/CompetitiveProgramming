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

ll n, k, pow2[32];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void sol() {
	cin >> n >> k;
	ll tamr = log2(k) + 1;
	ll res = 0;
	while (k > 1) {
		int l = 1, mid, r = tamr, ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (pow2[mid] - >= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		res = (res + mu(n, ans - 1)) % MOD;
		k -= pow2[ans - 1];
	}
	cout << res << '\n';
}

int main() {
	fastflow;
	pow2[0] = 1;
	for (int i = 1; i <= 30; i++) pow2[i] = pow2[i - 1] * 2;
	int t;
	cin >> t;
	while (t --) sol();
}
