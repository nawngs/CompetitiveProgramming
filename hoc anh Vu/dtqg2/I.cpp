#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, s[5003], ss[5003];

char a[5003][5003];

int cnt[5003], f[5003][5003], g[5003][5003];

// f = cnt[x][y] + cnt[x'][y']
// g = cnt[x][y] * x + cnt[x'][y'] * x'

int calc_val(int x, int y) {
	ll total = 0;
	total = 1ll * s[x] * 1ll * y + 1ll * s[y] * 1ll * x;
	total %= MOD;
	return total;
}

int calc_f(int x, int y) {
	return x * y;
}

int calc_g(int x, int y) {
	ll res = 1ll * ss[x] * 1ll * y;
	res %= MOD;
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 1; i <= NMAX; i++) {
		s[i] = (s[i - 1] + i * i) % MOD;
		ss[i] = (ss[i - 1] + i) % MOD;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		
	ll res = 0;
	for (int j = m; j >= 1; j--) {
		stack < pii > st;
		st.push({n + 1, 0});
		for (int i = n; i >= 1; i--) {
			if (a[i][j] == '0') {
				cnt[i] = 0;
				while (!st.empty()) st.pop();
				st.push({i, 0});
				continue;
			}
			cnt[i] ++;
			while (!st.empty() && cnt[st.top().fi] >= cnt[i]) 
				st.pop();
			int x = (st.top().fi - i), y = cnt[i], cur = st.top().se;
			cur = (cur + calc_val(x, y)) % MOD;
			f[i][j] = calc_f(x, y); g[i][j] = calc_g(x, y);
			ll temp = (1ll * x * 1ll * x * 1ll * f[st.top().fi][j]) % MOD;
			cur = (cur + temp) % MOD;
			temp = (2ll * x * g[st.top().fi][j]) % MOD;
			cur = (cur + temp) % MOD;
			f[i][j] = (f[i][j] + f[st.top().fi][j]) % MOD;
			temp = (1ll * g[st.top().fi][j] + 1ll * x * f[st.top().fi][j]) % MOD;
			g[i][j] = (g[i][j] + temp) % MOD;
			res = (res + cur) % MOD;
			st.push({i, cur});
		}
	}
	cout << res << '\n';
}