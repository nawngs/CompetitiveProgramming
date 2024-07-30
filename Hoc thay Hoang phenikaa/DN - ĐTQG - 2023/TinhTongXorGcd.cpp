#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

const int N = 1E5;
const int M = 1E6;

int n, a[N + 3], f[M + 3];

ll sl[N + 3], sr[N + 3], cntp[M + 3], cnt[M + 3], dp[M + 3];

vector < int > prime;

void sieve() {
	for (int i = 1; i <= M; i++) f[i] = i;
	for (int i = 2; i * i <= M; i++) if (f[i] == i)
		for (int j = i * i; j <= M; j+=i) f[j] = i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (int i = 1; i <= n; i++) {
		sl[i] = sl[i - 1];
		int x = a[i];
		prime.clear();
		while (x > 1) {
			int div = f[x];
			prime.pb(div);
			while (x % div == 0) x /= div;
		}
		for (int msk = 1; msk < (1 << (prime.size())); msk++) {
			int v = 1;
			for (int j = 0; j < prime.size(); j++) if (msk >> j & 1) v *= prime[j];
			if (__builtin_popcount(msk) & 1) sl[i] += cntp[v];
			else sl[i] -= cntp[v];
			cntp[v] ++;
		}
	}
	memset(cntp, 0, sizeof(cntp));
	for (int i = n; i >= 1; i--) {
		sr[i] = sr[i + 1];
		int x = a[i];
		prime.clear();
		while (x > 1) {
			int div = f[x];
			prime.pb(div);
			while (x % div == 0) x /= div;
		}
		for (int msk = 1; msk < (1 << (prime.size())); msk++) {
			int v = 1;
			for (int j = 0; j < prime.size(); j++) if (msk >> j & 1) v *= prime[j];
			if (__builtin_popcount(msk) & 1) sr[i] += cntp[v];
			else sr[i] -= cntp[v];
			cntp[v] ++;
		}
	}
	ll total = 0;
	for (int i = M; i > 1; i--) {
		ll temp = 0;
		for (int j = i; j <= M; j+=i) {
			dp[i] += cnt[j] * (cnt[j] - 1) / 2;
			dp[i] += temp * cnt[j];
			temp += cnt[j];
		}
		for (int j = 2 * i; j <= M; j+=i) dp[i] -= dp[j];
		// if (dp[i] != 0) cout << i << " " << dp[i] << '\n';
		total += dp[i];
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		// cout << total << " " << sl[i - 1] << " " << sr[i + 1] << '\n';
		res ^= ((total - sl[i - 1] - sr[i + 1]) & 1 ? a[i] : 0); 
	}
	cout << res;
}