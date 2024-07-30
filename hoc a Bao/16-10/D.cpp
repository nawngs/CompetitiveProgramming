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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, a[203], cnt[203], mx[203], f[203], g[203];

bool used[203];

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = 0;
		used[i] = 0;
		f[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cnt[a[i]] ++;
		if (cnt[a[i]] > k) {
			cout << -1 << '\n';
			return ;
		}
	}	
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		mx[i] = max(cnt[i], mx[i + 1]);
		g[i] = cnt[i] + g[i + 1];
	}
	vector < int > res;
	for (int t = 1; t <= n; t++) {
		bool ok = false;
		// cout << t << '\n';
		for (int i = 1; i <= n; i++) {
			// cout << i << " " << f[a[i]] + 1 + max(mx[a[i] + 1], g[a[i]] - g[a[i] + 1] - 1) << " " << f[a[i]] + g[a[i]] << '\n';
			if (!used[i] && f[a[i]] + 1 + max(mx[a[i] + 1], g[a[i]] - g[a[i] + 1] - 1) <= k && k <= f[a[i]] + g[a[i]]) {
				used[i] = 1;
				ok = 1;
				res.pb(a[i]);
				cnt[a[i]] --;
				for (int j = n; j >= 1; j--) {
					mx[j] = max(mx[j + 1], cnt[j]);
					g[j] = cnt[j] + g[j + 1];
				}
				f[a[i]] ++;
				for (int j = a[i] + 1; j <= n; j++) f[j] = max(f[j], f[j - 1]);
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
			return ;
		}
	}
	for (auto x : res) cout << x << " ";
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}