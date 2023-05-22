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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, p, a[100003];

int calc(int pre, int x) {
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= x + pre) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans - pre;
}

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0;
	for (int i = 1; i <= n; i++) l = max(l, a[i] - i + 1);
	int r = a[n];
	for (int i = 0; i < n; i++) {
		while (r >= l && calc(i, r) >= p) 
			r --;
		if (l > r) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << r - l + 1 << '\n';
	for (int i = l; i <= r; i++) cout << i << " ";
}