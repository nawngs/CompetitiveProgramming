#include <bits/stdc++.h>

#define pii pair < int, int >
#define ll long long

using namespace std;

ll n, sum = 1, f[12], m;
vector < pii > c[12];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x *= x;
	if (b % 2 == 1) x *= a;
	return x;

}

bool check(ll mid, ll lev) {
	if (lev == 0) return (1 >= m);
	bool tam = check(mid, lev / 2);
	if (tam == false) {
		ll x = mu(mid, lev / 2);
		x = x * x;
		if (lev % 2 == 1) x *= mid;
		return (sum * x >= m);
	}
	else return true;
}

void create_f(ll pos) {
	ll l = 1, r = c[pos].size(), mid, ans = 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid, n - pos + 1)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	f[pos] = ans;
	sum *= ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll x;
			cin >> x;
			c[i].push_back({x, j});
		}
		sort(c[i].begin(), c[i].end(), greater < pii >());
	}
	cin >> m;
	
	for (int i = 1; i <= n; i++) {
		create_f(i);
	}
}