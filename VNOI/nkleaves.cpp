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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, s[NMAX + 3], ss[NMAX + 3], dp[NMAX + 3][13], k;

ll get(int l, int r) {
	return ss[r - 1] - ss[l - 1] - (r - l) * s[l - 1];
}

void solve(int id, int l, int r, int optl, int optr) {
	if (l > r) return ;
	int mid = (l + r) / 2, opt;
	dp[mid][id] = LINF;	
	for (int i = optl; i <= min(optr, mid - 1); i++) {
		if (dp[mid][id] > dp[i][id - 1] + get(i + 1, mid)) {
			dp[mid][id] = dp[i][id - 1] + get(i + 1, mid);
			opt = i;	
		}
	}
	solve(id, l, mid - 1, optl, opt);
	solve(id, mid + 1, r, opt, optr);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> s[i];
	reverse(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
		ss[i] = ss[i - 1] + s[i];
		dp[i][1] = get(1, i);
	}
	for (int i = 2; i <= k; i++) solve(i, i, n, i - 1, n);
	cout << dp[n][k];
}