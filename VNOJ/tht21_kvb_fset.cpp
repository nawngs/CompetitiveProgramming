#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e6	;
const ll MOD = 1;

ll n, m, f[nmax + 5], a[nmax + 5], cnt[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;

	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * 2; j <= nmax; j += i) f[j] = i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	sang();
	for (int i = 1; i <= n; i++) {
		ll tam = i;
		ll pre = -1, dem = 0;
		a[i] = 1;
		while (tam > 1) {
			if (f[tam] == pre) dem ++;
			else {
				if (dem % 2 == 1) a[i] *= pre;
				dem = 1;
			}
			pre = f[tam];
			tam /= f[tam];
		}
		if (dem % 2 == 1) a[i] *= pre;
		cnt[a[i]] ++;
		//cout << a[i] << '\n';
	}
	ll ans = 1;
	for (int i = 1; i <= nmax; i++) {
		//cout << i << " " << cnt[i] + 1 << '\n';
		ans = (ans * (cnt[i] + 1)) % m;
	}
	cout << ans;
}
