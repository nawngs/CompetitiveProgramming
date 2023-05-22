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
const ll LINF = 1E15;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

double a[400003], b[400003], f[400003], s[400003];

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1, greater < double >());
	sort(b + 1, b + n + 1, greater < double >());
	f[0] = -LINF, s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] + b[i]);
		f[i] = max(f[i - 1], s[i] - i);
	}
	double res = 0, cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (s[mid] <= cur) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		res = max(res, f[ans] - i);
		if (ans < n) res = max(res, cur - i - ans - 1);
	}
	cout << fixed << setprecision(4) << res;
}