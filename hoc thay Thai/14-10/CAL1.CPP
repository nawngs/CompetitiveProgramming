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
const ll MOD = 1e6 + 3;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a, b, frac[MOD + 5];

ll mu(ll a, ll b, ll p) {
	if (b == 0) return (1 % p);
	ll x = mu(a, b / 2, p);
	x = (x * x) % p;
	if (b % 2 == 1) x = (x * a) % p;
	return x;
}

ll Ckn(ll n, ll k, ll p) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % p, p - 2, p)) % p;
}

int calculateUsingLT(int n, int r, int p) {
	if (r==0) return 1;
	int ni = n%p, ri = r%p;
	int res1 = calculateUsingLT(n/p, r/p, p);
	int res2 = Ckn(ni, ri, p);
	int res = (res1 * res2) % p;
	return res;
}
void sol() {
	cin >> a >> b >> n >> k;
	cout << ((mu(a, n - 1, MOD) * mu(b, k - 1, MOD)) % MOD * calculateUsingLT(n + k - 2, n - 1, MOD)) % MOD << '\n';
}

main() {
	fast;
	//fre();
	frac[0] = 1;
	for (int i = 1; i <= MOD; i++) frac[i] = (frac[i - 1] * i) % MOD;
	int t = 1;
	cin >> t;
	while (t --) sol();
}
