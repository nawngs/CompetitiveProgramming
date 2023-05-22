#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll MOD = 727355608;

ll n, a[7], res[1000005], cntle = 0, pow4[1000005];

vector < pair < ll, ll > > f;

void build() {
	pow4[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		pow4[i] = (pow4[i - 1] * 4) % MOD;
	}
}

int main() {
	build();
	cin >> n;
	ll s = 0, tam;
	for (int i = 1; i <= 3; i++) {
		cin >> a[i];
		s += a[i];
		if (a[i] % 2 == 1) {
			tam = i;
			cntle ++;
		}
	}
	a[0] = n - s;
	//cout << a[0] << '\n';
	if (a[0] % 2 == 1) {
		cntle ++;
		tam = 0;
	}
	if (cntle != n % 2 || (a[0] > n - 2 && n >= 2)) {
		cout << "Bedao!" << '\n';
		return 0;
	}
	if (n % 2 == 1) {
		res[(n + 1) / 2] = tam;
		a[tam] --;
	}
	tam = 1;
	while (a[tam] == 0 && tam <= 4) tam ++;
	//cout << tam << '\n';
	if (tam != 5) res[1] = res[n] = tam;
	a[tam] -= 2;
	tam = 3;
	for (int i = n / 2; i >= 2; i --) {
		while (a[tam] == 0) tam --;
		res[i] = tam;
		res[n - i + 1] = tam;
		a[tam] -= 2; 
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		//cout << res[i] << '\n';
		ans = (ans + (res[i] * pow4[i - 1]) % MOD) % MOD;
	}
	cout << ans;
}