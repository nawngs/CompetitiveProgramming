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

const string NAME = "psquare";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[100003], ans = 0, mu[100003], val[73], dp[70][(1 << 20)], f[nmax + 3], cur = 0;

vector < pll > b;

vector < int > prime;

bool g[nmax + 3], gg[23];

void back_track(int pos) {
	if (pos == n + 1) {
		ans += !cur;
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 1) {
			int x = a[pos];
			while (x > 1) {
				g[f[x]] ^= 1;
				if (g[f[x]]) cur ++;
				else cur --;
				x /= f[x];
			}
		}
		back_track(pos + 1);
	}
}

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i <= nmax; i++) {
		if (f[i] == i) 
			for (int j = 2 * i; j <= nmax; j += i) f[j] = i;
	}
}

void sub1() {
	sang();
	back_track(1);
	cout << ans - 1 << '\n';
	return ;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) sub1();
	else {
		mu[0] = 1;
		for (int i = 1; i <= n; i++) mu[i] = (mu[i - 1] * 2) % MOD;
		int timer = -1;
		for (int i = 2; i <= 70; i++) {
			bool th = true;
			for (int j = 2; j < i; j++) if (i % j == 0) th = false;
			if (th) {
				prime.push_back(i);
				val[i] = ++ timer;
			}
		}
		sort(a + 1, a + n + 1);
		int dem = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] == a[i - 1]) dem ++;
			else {
				b.push_back({a[i - 1], dem});
				dem = 1;
			}
		}
		b.push_back({a[n], dem});
		for (auto &x : b) {
			int val_ = 0;
			for (auto v : prime) {
				int dem = 0;
				while (x.fi % v == 0) {
					dem ++;
					x.fi /= v;
				}
				if (dem % 2 == 1) val_ += (1 << val[v]);
			}
			x.fi = val_;
		}
		dp[0][0] = (dp[0][0] + mu[b[0].se - 1]) % MOD;
		dp[0][b[0].fi] = (dp[0][b[0].fi] + mu[b[0].se - 1]) % MOD;
		for (int i = 0; i < b.size() - 1; i++) {
			for (int j = 0; j < (1 << 20); j++) {
				if (dp[i][j] == 0) continue;
				dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * mu[b[i + 1].se - 1] % MOD)) % MOD;
				dp[i + 1][(j ^ b[i + 1].fi)] = (dp[i + 1][(j ^ b[i + 1].fi)] + (dp[i][j] * mu[b[i + 1].se - 1] % MOD)) % MOD;
			}
		}
		cout << (dp[b.size() - 1][0] - 1 + MOD) % MOD << '\n';
	}
}

/*
	15
	62 63 65 60 64 62 62 61 64 63 61 65 62 61 63*/