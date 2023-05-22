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

const string NAME = "SOLDIER";
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

int n, k, a[5003];

namespace sub1 {
	bool dp[5003][5003];
	void solve() {
		for (int i = 1; i <= n; i++) {
			dp[0][0] = 1;
			for (int p = 1; p <= n; p++) {
				for (int q = 0; q <= k; q++) {
					dp[p][q] = dp[p - 1][q];
					if (p != i && q >= a[p]) dp[p][q] |= dp[p - 1][q - a[p]];
				}
			}
			bool th = false;
			for (int q = max(0, k - a[i]); q < k; q++) th |= dp[n][q];
			cout << th;
		}
	}
}

namespace ac {
	bool f[5003][5003];
	vector < int > valid[5003];
	void solve() {
		f[n + 1][0] = 1;
		valid[n + 1].push_back(0);
		for (int i = n; i >= 1; i--) {
			for (int j = 0; j <= k; j++) {
				f[i][j] = f[i + 1][j];
				if (j >= a[i]) f[i][j] |= f[i + 1][j - a[i]];
				if (f[i][j]) valid[i].push_back(j);
			}
		}
		memset(f, false, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				f[i][j] = f[i - 1][j];
				if (j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
			}
		}
		for (int i = 1; i <= n; i++) {
			int res = 0;
			for (int j = 0; j < k; j++) {
				if (!f[i - 1][j]) continue;
				int l = 0, r = valid[i + 1].size() - 1, mid, ans;
				while (l <= r) {
					mid = (l + r) / 2;
					if (j + valid[i + 1][mid] < k) {
						ans = valid[i + 1][mid];
						l = mid + 1;
					}
					else r = mid - 1;
				}
				res = max(res, j + ans);
			}
			if (res + a[i] >= k) cout << 1;
			else cout << 0;
		}
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	} 
	for (int i = 1; i <= n; i++) {
		if (s - a[i] < k) cout << 1;
		else cout << 0;
	}
	// if (n <= 400) sub1::solve();
	// else ac::solve();
}
