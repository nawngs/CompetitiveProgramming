#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("O1")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1E9 + 7;
const ll nmax = 1e7;

int n;

vector < int > f, cnt;

void sang() {
	f.resize(n + 5, 1);
	for (int i = 2; i * i <= n; i++) {
		if (f[i] == 1) for (int j =i * i; j <= n; j += i) f[j] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) f[i] = i;
	}
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	long long x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	cin >> n;
	sang();
	cnt.resize(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		ll tam = i;
		while (tam > 1) {
			cnt[f[tam]] ++;
			tam /= f[tam];
		}
	}
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		res = (res * mu(1ll * i, 1ll * (cnt[i] - (cnt[i]% 2)))) % MOD;
	}
	cout << res;
}
