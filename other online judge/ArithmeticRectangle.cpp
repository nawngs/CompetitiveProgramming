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
const int LINF = 2e9 + 7;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[3003][3003], cnt[3003][3003], pre[3003][3003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) 
		a[i][0] = a[i][m + 1] = LINF;
	for (int j = 1; j <= m; j++)
		a[0][j] = a[n + 1][j] = LINF;
	int res = 1;
	for (int j = 1; j <= m; j++) {
		cnt[1][j] = 1;
		for (int i = 2; i <= n; i++) {
			if (i > 2 && a[i][j] - a[i - 1][j] == a[i - 1][j] - a[i - 2][j]) cnt[i][j] = cnt[i - 1][j] + 1;
			else cnt[i][j] = 2;
			res = max(res, cnt[i][j]);
		}

	}
	for (int i = 1; i <= n; i++) {
		res = max(res, cnt[i][1]);
		stack < pii > st;
		for (int j = 2; j <= m; j++) {
			if (a[i][j] - a[i][j - 1] != a[i][j - 1] - a[i][j - 2]
			|| a[i - 1][j] - a[i - 1][j - 1] != a[i - 1][j - 1] - a[i - 1][j - 2]) {
				while (!st.empty()) st.pop();
				st.push({-INF, j - 2}); st.push({cnt[i][j - 1], j - 1});
			}
			while (st.top().fi >= cnt[i][j]) st.pop();
			pre[i][j] = st.top().se;
			res = max(res, (j - pre[i][j]) * cnt[i][j]);
			st.push({cnt[i][j], j});
		}
		while (!st.empty()) st.pop();
		res = max(res, cnt[i][m]);
		for (int j = m - 1; j >= 1; j--) {
			if (a[i][j] - a[i][j + 1] != a[i][j + 1] - a[i][j + 2] 
			|| a[i - 1][j] - a[i - 1][j + 1] != a[i - 1][j + 1] - a[i - 1][j + 2]) {
				while (!st.empty()) st.pop();
				st.push({-INF, j + 2}); st.push({cnt[i][j + 1], j + 1});
			}
			while (st.top().fi >= cnt[i][j]) st.pop();
			int pos = st.top().se;

			res = max(res, (pos - j) * cnt[i][j]);
			if (a[i][j] - a[i][j - 1] == a[i][j + 1] - a[i][j] 
			&& a[i - 1][j] - a[i - 1][j - 1] == a[i - 1][j + 1] - a[i - 1][j]) 
			res = max(res, (pos - pre[i][j] - 1) * cnt[i][j]);
			st.push({cnt[i][j], j});
		}
		//cout << i << " " << res << '\n';
	}
	for (int i = 1; i <= n; i++) {
		cnt[i][1] = 1;
		for (int j = 2; j <= m; j++) {
			if (a[i][j] - a[i][j - 1] == a[i][j - 1] - a[i][j - 2]) cnt[i][j] = cnt[i][j - 1] + 1;
			else cnt[i][j] = 2;
			res = max(res, cnt[i][j]);
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}