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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll K, d, dp[20][1024][2][2], res[1024];

string A, B;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	if (n < k) return 0;
	ll up = 1, down = 1;
	for (ll i = 1; i <= k; i++) {
		up *= (n - i + 1) % MOD;
		down *= i;
		up %= MOD;
		down %= MOD;
	}
	return (up * mu(down, MOD - 2)) % MOD;
}

void sol() {
	cin >> A >> B >> K >> d;
	while (A.size() < B.size()) A = '0' + A;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	bool th = false;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != '0') th = 1;
		for (int bit = 0; bit < (1 << 10); bit++) {
			for (int f1 = 0; f1 < 2; f1++) {
				for (int f2 = 0; f2 < 2; f2++) {
					for (int digit = 0; digit <= 9; digit++) {
						if ((f1 || digit >= (A[i] - '0')) && (f2 || digit <= (B[i] - '0'))) {
							int new_f1 = (f1 || digit > (A[i] - '0'));
							int new_f2 = (f2 || digit < (B[i] - '0'));
							int new_bit = bit;
							if (new_f1 || th) new_bit |= (1 << digit);
							dp[i + 1][new_bit][new_f1][new_f2] += dp[i][bit][f1][f2];
						}
					}
				}
			}
		}
	}
	memset(res, 0, sizeof(res));
	for (int bit = 0; bit < (1 << 10); bit++) 
		for (int bit2 = bit; bit2 < (1 << 10); bit2++) 
			if ((bit2 & bit) == bit) 
				res[bit] += dp[A.size()][bit2][0][0] + dp[A.size()][bit2][1][0] + dp[A.size()][bit2][0][1] + dp[A.size()][bit2][1][1];
	ll ans = 0;
	for (int mask = 0; mask < (1 << 10); mask++) {
		if (__builtin_popcount(mask) == d) {
			for (int mask2 = mask; mask2 < (1 << 10); mask2++) {
				if ((mask2 & mask) == mask) {
					if ((__builtin_popcount(mask2) - d) & 1) ans -= Ckn(K, res[mask2]);
					else ans += Ckn(K, res[mask2]);
					ans %= MOD;
				}
			}
		}
	}
	cout << (ans + MOD) % MOD << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
