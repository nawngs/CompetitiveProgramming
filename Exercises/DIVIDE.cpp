#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, dp[5005][2505], trace[5005][2505];

pair < int, pair < int, int > > a[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DIVIDE.inp", "r", stdin);
	freopen("DIVIDE.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se.se = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i].se.fi;
	sort(a + 1, a + n + 1, [](pair < int, pair < int, int > > & x, pair < int, pair < int, int > > & y){
		return x.fi > y.fi;
	});
	for (int i = 1; i <= n; i++) {
		//cout << a[i].fi << " " << a[i].se.fi << '\n';
		for (int j = 1; j <= i / 2; j ++) {
			if (dp[i - 1][j] >  dp[i - 1][j - 1] + a[i].se.fi) {
				dp[i][j] = dp[i - 1][j];
				trace[i][j] = i - 1;
			}
			else {
				dp[i][j] =  dp[i - 1][j - 1] + a[i].se.fi;
				trace[i][j] = i;
			}
		}
	}
	cout << dp[n][n / 2] << '\n';
	int pos = n, k = n / 2;
	deque < int > q;
	int f[5005];
	memset(f, 0, sizeof(f));
	while (n >= 1 && k >= 1) {
		if (trace[pos][k] == pos) {
			f[pos] = 1;
			q.push_back(pos);
			pos --;
			k --;
		}
		else {
			pos --;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (f[i] == 0) {
			cout << a[q.back()].se.se << " " << a[i].se.se << '\n';
			q.pop_back();
		}
	}
}