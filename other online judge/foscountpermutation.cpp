#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, frac[100003];

int a[100003], c[100003];

int st[100003][23];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

int get(int l, int r) {
	int k = log2(r - l + 1);
	if (a[st[l][k]] > a[st[r - (1 << k) + 1][k]]) return st[l][k];
	else return st[r - (1 << k) + 1][k];
}

ll find_ans(int l, int r) {
	if (l >= r) return 1;
	int pos = get(l, r);
	return ((C(pos - l, r - l) * find_ans(l, pos - 1)) % MOD * find_ans(pos + 1, r)) % MOD;
}

ll get_Res()	

main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if (a[st[i][j - 1]] > a[st[i + (1 << (j - 1))][j - 1]]) st[i][j] = st[i][j - 1];
			else st[i][j] = st[i + (1 << (j - 1))][j - 1];
		}
	frac[0] = 1;
	for (int i = 1; i <= n; i++) 
		frac[i] = (frac[i - 1] * i) % MOD;
	cout << find_ans(1, n);
}
