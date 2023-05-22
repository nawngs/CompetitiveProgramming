#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Query {
	int c1, r2, c2, id;
	Query(int _c1, int _r2, int _c2, int _id) {
		c1 = _c1, r2 = _r2, c2 = _c2, id = _id;
	}
};

int n, m, q;

bool res[1000003];

vector < Query > query[1003];

bitset < 1001 > a[1003], dp1[1003][1003], temp, dp2[1003][1003];

void solve(int up, int down) {
	if (up > down) return ;
	int mid = (up + down) / 2;
	for (int i = up; i <= down; i++)
		for (int j = 1; j <= m; j++) {
			dp1[i][j] = dp2[i][j] = 0;
		}
	dp1[mid][m][m] = a[mid][m];
	for (int j = m - 1; j >= 1; j--) {
		if (a[mid][j] == 0) dp1[mid][j] = 0;
		else {
			dp1[mid][j] = dp1[mid][j + 1];
			dp1[mid][j][j] = 1;
		}
	}
	dp2[mid][1][1] = a[mid][1];
	for (int j = 2; j <= m; j++) {
		if (a[mid][j] == 0) dp2[mid][j] = 0;
		else {
			dp2[mid][j] = dp2[mid][j - 1];
			dp2[mid][j][j] = 1;
		}
	}
	for (int i = mid - 1; i >= up; i--) {
		if (a[i][m]) dp1[i][m] = dp1[i + 1][m];
		else dp1[i][m] = 0;
		for (int j = m - 1; j >= 1; j--) {
			if (!a[i][j]) dp1[i][j] = 0;
			else dp1[i][j] = dp1[i + 1][j] | dp1[i][j + 1];
		}
	}
	for (int i = mid + 1; i <= down; i++) {
		if (!a[i][1]) dp2[i][1] = 0;
		else dp2[i][1] = dp2[i - 1][1];
		for (int j = 2; j <= m; j++) {
			if (!a[i][j]) dp2[i][j] = 0;
			else dp2[i][j] = dp2[i - 1][j] | dp2[i][j - 1];
		}
	}
	for (int r1 = up; r1 <= mid; r1++) {
		while (sz(query[r1])) {
			auto x = query[r1].back();
			if (x.r2 < mid) break;
			temp = dp1[r1][x.c1] & dp2[x.r2][x.c2];
			res[x.id] = temp.count();
			query[r1].pop_back(); 
		}
	}
	solve(up, mid - 1); solve(mid + 1, down);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			if (c == '.') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (int i = 1; i <= q; i++) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
		query[r1].pb(Query(c1, r2, c2, i));
	}
	for (int i = 1; i <= n; i++)
		sort(query[i].begin(), query[i].end(), [&](Query &x, Query &y) {
			return x.r2 < y.r2;
		});
	solve(1, n);
	for (int i = 1; i <= q; i++) {
		cout << (res[i] ? "YES" : "NO") << '\n';
	}
}