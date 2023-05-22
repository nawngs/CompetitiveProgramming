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

ll n, k, cnta[200003], dp[503][503][503], cntb[200003], preb[200003], prea[200003];

string s;

int find(int pos, int sz) {
	int l = 1, r = pos, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (cnta[pos] - cnta[mid - 1] >= sz) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

ll calc(int r, int song, int rem) {
	if (r == 0) return 0;
	if (song == 0) return LINF;
	ll ans = LINF;
	int pre = -1, pos = r + 1, cnt = 0;
	for (int i = 0; i + rem <= (r + rem) / 2; i++) {
		if (i + rem == 0) continue;
		if (pre == -1) pre = find(r, i + rem);
		else pre = prea[pre - 1];
		if (i == 0) {
			ans = min(ans, calc(pre - 1, song - 1, cntb[r] - cntb[pre - 1]));
			continue;
		}
		cnt += (r - i + 1) - preb[pos - 1];
		pos = preb[pos - 1];
		ans = min(ans, cnt + calc(pre - 1, song - 1, cntb[r] - cntb[pre - 1] - i));
		if (r == n) cout << i << " " << cnt << " " << pre - 1 << " " << calc(pre - 1, song - 1, cntb[r] - cntb[pre - 1] - i) << '\n';
	}
	//cout << r << " " << song << " " << rem << " " << ans << '\n';
	return ans;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s;
	s = ' ' + s; n = n * 2;
	for (int i = 1; i <= n; i++) {
		cntb[i] = cntb[i - 1] + (s[i] == 'B');
		cnta[i] = cnta[i - 1] + (s[i] == 'A');
		if (s[i] == 'B') {
			preb[i] = i;
			prea[i] = prea[i - 1];
		}
		else {
			preb[i] = preb[i - 1];
			prea[i] = i;
		}
	}
	cout << calc(n, k, 0);
}