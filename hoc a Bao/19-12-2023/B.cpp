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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 19;

int n, a[N + 3], mx[N + 3][LG + 3], mn[N + 3][LG + 3];

int get_mx(int l, int r) {
	int k = __lg(r - l + 1);
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}

int get_mn(int l, int r) {
	int k = __lg(r - l + 1);
	return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx[i][0] = mn[i][0] = a[i];
	}
	for (int j = 1; j <= LG; j++)
	for (int i = 1; i + (1 << j) - 1 <= n; i++) {
		mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
	}
	// cout << get_mx(6, n) << '\n';
	for (int i = 1; i <= n; i++) {
		int x = get_mx(1, i);
		int l = 1, r = n, mid, ansl = n + 1, ansr = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			// if (i == 2) cout << mid << " " << get_mx(mid, n) << " " << x << '\n';
			if (get_mx(mid, n) <= x) {
				ansl = mid;	
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (ansl == n + 1 || get_mx(ansl, n) != x) continue;
		l = 1, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			// if (i == 5) cout << mid << " " << get_mx(mid, n) << " " << x << '\n';
			if (get_mx(mid, n) >= x) {
				ansr = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		l = max(i + 1, ansl - 1), r = ansr - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			int y = get_mn(i + 1, mid);
			if (y == x) {
				cout << "YES" << '\n' << i << " " << mid - i << " " << n - mid << '\n';
				return ;
			}
			if (y < x) r = mid - 1;
			else l = mid + 1;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}