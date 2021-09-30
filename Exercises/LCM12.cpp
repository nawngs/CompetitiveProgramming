#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e6;
const ll MOD = 1E9;

ll f[nmax + 5], cnt[nmax + 5], res[nmax + 5];

bool check[nmax + 5];

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;

	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * 2; j <= nmax; j += i) f[j] = i;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x = (x * a);
	return x;
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("LCM12.inp", "r", stdin);
	freopen("LCM12.out", "w", stdout);
	sang();
	memset(check, false, sizeof(check));
	//cout << mu(10, 1) << '\n';
	res[1] = 1;
	for (int i = 2; i <= nmax; i++) {
		res[i] = res[i - 1];
		ll tam = i;
		ll pre = -1, dem = 0;
		while (tam > 1) {
			if (f[tam] == pre) dem ++;
			else {
				if (cnt[pre] < dem) {
					res[i] *= mu(pre, dem - cnt[pre]);
					cnt[pre] = dem;
					res[i] %= MOD;
				}
				dem = 1;
			}
			pre = f[tam];
			tam /= f[tam];
		}
		//cout << res[i] << '\n';
		if (cnt[pre] < dem) {
			//cout << pre << " " << dem << " " << cnt[pre] << '\n';
			res[i] *= mu(pre, dem - cnt[pre]);
			//cout << i << " " << res[i] << '\n';
			cnt[pre] = dem;
			//cout << MOD << '\n';
			res[i] %= MOD;
		}
		//cout << i << " " << res[i] << '\n';
	}
	ll t;
	while (cin >> t) {
		if (t == 0) return 0;
		ll temp = res[t];
		while (temp % 10 == 0) temp /= 10;
		cout << temp % 10 << '\n';
	}
}
