#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "course";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[2003], m, val[2003][2003], s[2003], finish[2003], dp[2003];

vector < ll > am;

void sol2() {
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (m --) {
		ll x;
		cin >> x;
		dp[0] = x;
		for (int i = 1; i <= n; i++) dp[i] = -INF;
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				if (dp[j - 1] >= 0 && dp[j - 1] + a[i] >= 0) dp[j] = max(dp[j], dp[j - 1] + a[i]);
			}
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++) if (dp[i] > 0) ans = max(ans, 1ll * i);
		cout << ans << ' ';
	}
}

void sol1() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) val[i][j] = -INF;

	int pos = 1;
	while (pos <= n) {
		if (a[pos] >= 0) pos ++;
		else {
			am.push_back(pos);
			int tam = pos;
			while (tam <= n) {
				if (a[tam] >= 0) break;
				for (int i = n; i >= 1; i--) val[pos][i] = max(val[pos][i], val[pos][i - 1] + a[tam]);
				tam ++; 
			}
			finish[pos] = tam - 1;
			pos = tam;
		}
	}
	for (int i = 1; i <= m; i++) {
		ll q;
		cin >> q;
		ll pre = 0;
		ll res = 0;
		ll temp = q;
		for (auto x : am) {
			res += x - 1 - pre;
			temp += s[x - 1] - s[pre];
			if (x == n + 1) continue;
			int l = 1, r = n, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (temp + val[x][mid] >= 0) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			res += ans;
			temp += val[x][ans];
			pre = finish[x];
		}
		res += n - pre;
		cout << res << ' ';
	}
}

void sol() {
	cin >> n >> m;
	if (n * n * m <= 1e8) sol2();
	else sol1();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
