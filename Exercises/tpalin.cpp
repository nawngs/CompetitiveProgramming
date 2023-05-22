#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "tpalin";
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

int n, a[200003], cnt[203], cntl[200003][203];

void sol() {
	cin >> n;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= 200; j++) cntl[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= 200; j++) cntl[i][j] = cntl[i - 1][j];
		cntl[i][a[i]] ++;
	}
	int res = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		cnt[a[i]] ++;
		int l = 1, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (cntl[n][a[i]] - cntl[mid - 1][a[i]] >= cnt[a[i]]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans --;
		if (ans <= i) continue;
		for (int j = 1; j <= 200; j++) res = max(res, 2 * cnt[a[i]] + cntl[ans][j] - cntl[i][j]);
	}
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}