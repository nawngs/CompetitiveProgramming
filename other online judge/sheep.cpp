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
const int N = 600;
const int M = 2E4;
const ll BASE = 2309;

struct Pt {
	ll x, y;
	Pt(ll x = 0, ll y = 0) : x(x), y(y) {}
	Pt& operator -= (const Pt &oth) {
		x -= oth.x, y -= oth.y;
		return (*this);
	}
	Pt operator - (const Pt &oth) const {
		return Pt(*this) -= oth;
	}
} a[N + 3], b[M + 3];

int n, m, MOD, cnt[N + 3][N + 3], dp[N + 3][N + 3];

bool invalid[N + 3][N + 3];

ll cross(const Pt &x, const Pt &y) {
	return x.x * y.y - x.y * y.x;
}

ll orient(const Pt &a, const Pt &b, const Pt &c) {
	return cross(b - a, c - a);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> MOD;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	for (int i = 0; i < m; i++) cin >> b[i].x >> b[i].y;
	for (int i = 0; i < m; i++) {
		int r = 0;
		for (int l = 0; l < n; l++) {
			while (l == r || orient(a[l], b[i], a[r]) > 0) {
				r = (r + 1) % n;
			}
			if (orient(a[l], b[i], a[r]) == 0) invalid[l][r] = 1;
			cnt[l][r] ++;
		}	
	}
	for (int l = 0; l < n; l++) {
		dp[l][(l + 1) % n] = 1;
		for (int r = 1; r <= n; r++) cnt[l][(l + r) % n] += cnt[l][(l + r - 1) % n];
	}
	for (int len = 2; len < n; len++) 
	for (int l = 0; l < n; l++) {
		int r = (l + len) % n;
		if (invalid[l][r]) dp[l][r] = 0;
		else {
			for (int t = 1; t < len; t++) {
				int k = (l + t) % n;
				int dem = m - cnt[l][k] - cnt[k][r] - cnt[r][l];
				if (!(dem & 1)) dp[l][r] += dp[l][k] * dp[k][r], dp[l][r] %= MOD;
			}
		}
		// cout << l << " " << r << " " << dp[l][r] << '\n';
	}
	cout << dp[1][0];
}