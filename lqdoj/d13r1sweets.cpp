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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, a[NMAX + 3], total = 0, val = 0, res[NMAX + 3];

bool maximize(int &x, int y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

namespace sub12 {
	int dp[(1 << 20)], trace[(1 << 20)];
	ll s[(1 << 20)];
	void solve() {
		dp[0] = 0;
		for (int msk = 1; msk < (1 << n); msk++) {
			dp[msk] = -1;
			for (int j = 0; j < n; j++) if (msk >> j & 1) {
				s[msk] = s[msk ^ (1 << j)] + a[j + 1];
				ll rem = s[msk] - dp[msk ^ (1 << j)] * val;
				if (maximize(dp[msk], dp[msk ^ (1 << j)] + (rem == val))) trace[msk] = j;
			}
		}
		if (dp[(1 << n) - 1] != k) {
			cout << -1 << '\n';
			return ;
		}
		int cur = (1 << n) - 1;
		while (cur > 0) {
			int id = (s[cur] == dp[cur] * val ? dp[cur] : dp[cur] + 1);
			res[trace[cur] + 1] = id;
			cur = cur ^ (1 << trace[cur]);
		}
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
	}
}

namespace sub3 {
	const int N = 100;
	pair < bool, int > dpl[N + 3][N * N + 3], dpr[N + 3][N * N + 3];
	void solve() {
		dpl[0][0] = {1, 0};
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= N * N; j++) {
				dpl[i][j] = dpl[i - 1][j];
				if (j >= a[i] && !dpl[i][j].fi && dpl[i - 1][j - a[i]].fi) dpl[i][j] = mp(1, i);
			}
		dpr[n + 1][0] = {1, n + 1};
		for (int i = n; i >= 1; i--)
			for (int j = 0; j <= N * N; j++) {
				dpr[i][j] = dpr[i + 1][j];
				if (j >= a[i] && !dpr[i][j].fi && dpr[i + 1][j - a[i]].fi) dpr[i][j] = mp(1, i);
			}
		for (int i = 1; i < n; i++) if (dpl[i][val].fi && dpr[i + 1][val].fi) {
			pii cur = {i, val};
			while (cur.fi >= 1) {
				int id = dpl[cur.fi][cur.se].se;
				res[id] = 1;
				cur.fi = id - 1; cur.se -= a[id]; 
			}
			cur = mp(i + 1, val);
			while (cur.fi <= n) {
				int id = dpr[cur.fi][cur.se].se;
				res[id] = 2;
				cur.fi = id + 1; cur.se -= a[id];
			}
			for (int j = 1; j <= n; j++) cout << res[j] + 1 << ' ';
			return ;
		}
		cout << -1 << '\n';
		return ;
	}
}

namespace ac {
	void solve() {
		ll i = n, cur = 0, id = 1;
		if (val < n) {
			cout << -1 << '\n';
			return ;
		}
		while (i) {
			if (res[i]) {
				i --;
				continue;
			}
			if (cur + i > val) {
				int rem = val - cur, j = rem;
				while (rem) {
					while (res[j]) j--;
					rem -= j; res[j--] = id;
					if (j > rem) j = rem;
				}
				id ++; cur = 0;
			}
			else {
				cur += i;
				res[i --] = id; 
			}
		}
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
		// for (int i = 1; i <= n; i++) s[res[i]] += i;
		// for (int i = 1; i <= k; i++) cout << s[i] << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		//a[i] = i;
		total += a[i];
	}
	if (total % k != 0) {
		cout << -1 << '\n';
		return 0;
	}
	val = total / k;
	if (n <= 20) sub12::solve();
	else 
	if (n <= 100) sub3::solve();
	else 
	ac::solve();
}