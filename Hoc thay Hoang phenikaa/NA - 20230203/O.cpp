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

ll n, a[200003], s[200003], k, sum_s[200003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	ll total = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i]; sum_s[i] = sum_s[i - 1] + s[i];
		int l = 0, r = i, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (s[i] - s[mid] <= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cnt += i - ans;
		total += s[i] * (i - ans) - (sum_s[i - 1] - (ans == 0 ? 0 : sum_s[ans - 1]));
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		a[i] = a[i - n];
		s[i] = s[i - 1] + a[i]; sum_s[i] = sum_s[i - 1] + s[i];
	}
	cout << total << " " << cnt << '\n';
	for (int i = 1; i < n; i++) {
		int l = i, r = i + n - 1, mid, ans = i - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (s[mid] - s[i - 1] <= k) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		total = total - (sum_s[ans] - sum_s[i - 1]) + s[i - 1] * (ans - i + 1); 
		cnt = cnt - (ans - i + 1);
		l = i, r = n + i;
		while (l <= r) {
			mid = (l + r) / 2;
			if (s[i + n] - s[mid] <= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cnt += i + n - ans;
		total = total + s[i + n] * (i + n - ans) - (sum_s[i + n - 1] - sum_s[ans - 1]);
		cout << total << " " << cnt << '\n';
	}
}