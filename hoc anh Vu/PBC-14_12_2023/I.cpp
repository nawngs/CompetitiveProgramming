#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 998244353;
const ll BASE = 2309;

int n, a[N + 3], m;

vector < int > prime;

int get(int x, int m) {
	prime.clear();
	for (int i = 2; i * i <= x; i++) if (x % i == 0) {
		prime.pb(i);
		while (x % i == 0) x /= i;
	}
	if (x != 1) prime.pb(x);
	int res = m, sz = SZE(prime);
	for (int msk = 1; msk < (1 << sz); msk++) {
		int v = 1;
		for (int i = 0; i < sz; i++) if (msk >> i & 1) v *= prime[i];
		if (__builtin_popcount(msk) & 1) res -= m / v;
		else res += m / v;
	}
	return res;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i < n; i++) if (a[i] % a[i + 1] != 0) {
		cout << 0 << '\n';
		return ;
	}
	ll res = 1;
	for (int i = 2; i <= n; i++) res = (res * 1ll * get(a[i - 1] / a[i], m / a[i])) % MOD;
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}