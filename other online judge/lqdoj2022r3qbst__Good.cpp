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

const string NAME = "qbst";
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

ll n, c[100003], w[100003], s[100003];

namespace sub1 {
	ll dp[403][403];
	void trace(int l, int r) {
		if (r < l) return ;
		if (l == r) {
			cout << l << " ";
			return ;
		}
		for (int k = r; k > l; k--) {
			if (dp[l][r] == max(dp[l][k - 1], max(dp[k + 1][r], c[k] + s[r] - s[l - 1] - w[k]))) {
				cout << k << " ";
				trace(l, k - 1);
				trace(k + 1, r);
				return ;
			}
		}
	}
	void solve() {
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i <= n - len + 1; i++) {
				int j = i + len - 1;
				if (len == 1) 
					dp[i][j] = c[i];
				else {
					dp[i][j] = LINF;
					for (int k = i + 1; k <= j; k++) 
						dp[i][j] = min(dp[i][j], max(dp[i][k - 1], max(dp[k + 1][j], c[k] + s[j] - s[i - 1] - w[k])));
				}
			}
		}
		cout << dp[1][n] << '\n';
		trace(1, n);
	}
}

namespace ac {
	ll st[3003][15];
	ll get(int l, int r) {
		int k = log2(r - l + 1);
		if (c[st[l][k]] < c[st[r - (1 << k) + 1][k]]) return st[l][k];
		else return st[r - (1 << k) + 1][k];
	}
	bool check(int l, int r, ll x) {
		if (r - l <= 1) return true;
		int pos = get(l + 1, r);
		//cout << l << " " << r << " " << pos << '\n';
		ll temp = s[r] - s[l - 1] + c[pos];
		if (temp > x) return false;
		return (check(l, pos - 1, x) && check(pos + 1, r, x));

	}
	void trace(int l, int r, ll val) {
		if (r < l) return ;
		if (l == r) {
			cout << l << " ";
			return ;
		}
		int low = l + 1, high = r, mid, ans;
		while (low <= high) {
			mid = (low + high) / 2;
			int pos = get(mid, r);
			ll temp = s[r] - s[l - 1] + c[pos];
			if (temp <= val) {
				ans = pos;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		cout << ans << ' ';
		trace(l, ans - 1, val);
		trace(ans + 1, r, val);
	}
	void solve() {
		ll l = 1, r = LINF, mid, ans;
		for (int i = 1; i <= n; i++)
			l = max(l, c[i]);
		for (int i = 1; i <= n; i++) {
			c[i] = c[i] - w[i];
			st[i][0] = i;
		}
		for (int i = 1; (1 << i) <= n; i++)
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
				if (c[st[j][i - 1]] < c[st[j + (1 << (i - 1))][i - 1]])
					st[j][i] = st[j][i - 1];
				else st[j][i] = st[j + (1 << (i - 1))][i - 1];
			}
		//check(1, n, 7);
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(1, n, mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
		trace(1, n, ans);
	}
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
	}
	if (n <= 400) sub1::solve();
	else ac::solve();
}
