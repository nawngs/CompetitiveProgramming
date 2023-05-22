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

int n, cnt[73][2], dp[73][(1 << 20)];

bool IsPrime[73];

vector < int > prime;

void sieve() {
	memset(IsPrime, 1, sizeof(IsPrime));
	for (int i = 2; i * i <= 70; i++)
		if (IsPrime[i])
			for (int j = i * i; j <= 70; j+=i) IsPrime[j] = false;
	for (int i = 2; i <= 70; i++)
		if (IsPrime[i]) prime.push_back(i);
}

int main() {
	fast;
	//fre();
	sieve();
	for (int i = 1; i <= 70; i++)
		cnt[i][0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ll temp = cnt[x][0];
		cnt[x][0] = (cnt[x][0] + cnt[x][1]) % MOD;
		cnt[x][1] = (cnt[x][1] + temp) % MOD;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 70; i++) {
		int x = i, mask = 0;
		for (int j = 0; j < prime.size(); j++) {
			int dem = 0;
			while (x % prime[j] == 0) {
				x /= prime[j];
				dem ^= 1;
			}
			if (dem) mask ^= (1 << j);
		}
		for (int j = 0; j < (1 << 19); j++) {
			dp[i][j] = (dp[i][j] + (1ll * dp[i - 1][j] * cnt[i][0]) % MOD) % MOD;
			dp[i][j ^ mask] = (dp[i][j ^ mask] + (1ll * dp[i - 1][j] * cnt[i][1]) % MOD) % MOD;
		}
	}
	cout << (dp[70][0] - 1 + MOD) % MOD;
}
