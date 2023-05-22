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

ll m, n, a[1003][1003], s[1003][1003];

signed main() {
	fast;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
		sort(a[i] + 1, a[i] + n + 1);
		for (int j = 1; j <= n; j++) s[i][j] = s[i][j - 1] + a[i][j];
		a[i][0] = -INF;
	}

	ll res = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			int l = 1, r = n, mid, ans;
			while (l <= r) {
				mid = (l + r) / 2;
				if (a[i][mid] >= a[j][n - mid]) {
					ans = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}`
			l = 1, r = n;
			int ans2;
			while (l <= r) {
				mid = (l + r) / 2;
				if (a[j][mid] >= a[i][n - mid]) {
					ans2 = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			if (a[i][ans] < a[j][ans2]) {
				res += a[i][ans] * ans - s[i][ans] + (s[i][n] - s[i][ans]) - a[i][ans] * (n - ans);
				res += a[i][ans] * (n - ans) - s[j][n - ans] + (s[j][n] - s[j][n - ans]) - a[i][ans] * ans;
			}
			else {
				res += a[j][ans2] * ans2 - s[j][ans2] + (s[j][n] - s[j][ans2]) - a[j][ans2] * (n - ans2);
				res += a[j][ans2] * (n - ans2) - s[i][n - ans2] + (s[i][n] - s[i][n - ans2]) - a[j][ans2] * ans2;
			}
		}
	}
	cout << res;
}
 