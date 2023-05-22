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

const string NAME = "guide";
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

int n, m, k, s[2005][2005], sum[2005][2005], pos1, pos2;

pii a[2005];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + m + 1, [](pii &x, pii &y) {
		return (x.se < y.se);
	});
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) s[i][j] = (max(0, min(a[j].se, i + k - 1) - max(a[j].fi, i) + 1));	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = 0;
			for (int k = 1; k <= m; k++) {
				sum += max(s[i][k], s[j][k]);
				if (i == 65 && j == 135) {
					cout << (s[i][k] >= s[j][k] ? 1 : 2) << '\n';
				}
			}
			if (sum > ans) {
				pos1 = i;
				pos2 = j;
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << " " << pos1 << " " << pos2;  
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
