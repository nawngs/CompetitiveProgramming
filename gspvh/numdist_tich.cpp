#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "numdist";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e7;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100001];

int pw[7];

int cnt[19487172];

ll f[1 << 7];

vector < short > digit[100003];

bool th = 0;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == nmax) {
			n --;
			i --;
			th = 1;
			continue;
		}
		int x = a[i];
		while (x > 0) {
			digit[i].push_back(x % 10);
			x /= 10;
		}
		while (digit[i].size() < 7) digit[i].push_back(0);
		reverse(digit[i].begin(), digit[i].end());
	}
	pw[0] = 1;
	for (int i = 1; i < 7; i++)
		pw[i] = (pw[i - 1] * 11) % MOD;
	for (int i = 1; i <= n; i++) {
		for (int bit = 0; bit < (1 << 7); bit++) {
			int val = 0;
			for (int j = 0; j < 7; j++) {
				if (!(bit >> j & 1)) val += digit[i][j] * pw[j];
				else val += 10 * pw[j];
			}
			f[bit] += cnt[val]; cnt[val] ++;
		}
	}
	ll res = 1;
	for (int mask = 0; mask < (1 << 7); mask++) {
		for (int sub = 0; sub < mask; sub++) 
			if ((mask & sub) == sub) 
				f[mask] -= f[sub];
		res = (res * mu(__builtin_popcount(mask), f[mask])) % MOD;
	}
	if (th) {
		for (int i = 1; i <= n; i++) {
			int x = a[i];
			digit[i].clear();
			while (x > 0) {
				digit[i].push_back(x % 10);
				x /= 10;
			}
			while (digit[i].size() < 8) digit[i].push_back(0);
			reverse(digit[i].begin(), digit[i].end());
			int cnt = 0;
			x = nmax;
			while (x > 0) {
				cnt += (x % 10 != digit[i].back());
				digit[i].pop_back(); x /= 10;
			}
			res = (res * 1ll * cnt) % MOD;
		}
	}
	cout << res << '\n';
}
