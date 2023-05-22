#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "fc071_prime";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll pos[nmax + 5], s[nmax + 5], sum[nmax + 5];

bool f[nmax + 5];

void create() {
	for (int i = 1; i <= nmax; i++) f[i] = true;
	f[1] = f[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (f[i]) for (int j = i * i; j <= nmax; j+=i) f[j] = false;
	int dem = 1;
	for (int i = 0; i <= nmax; i++) {
		pos[i] = dem;
		s[i] = s[i - 1];
		sum[i] = sum[i - 1];
		if (f[i]) {
			dem ++;
			s[i] += (dem - 1) * i;
			s[i] %= MOD;
			sum[i] += i;
			sum[i] %= MOD;
		}
	}
}

void sol() {
	ll r, l;
	cin >> l >> r;
	ll tam = ((s[r] - s[l - 1]) % MOD + MOD) % MOD;
	ll temp = ((sum[r] - sum[l - 1]) % MOD + MOD) % MOD;
	tam = ((tam - (temp * (pos[l] - 1) % MOD) % MOD) + MOD) % MOD;
	cout << tam << '\n';
}

int main() {
	fast;
	//fre();
	create();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
