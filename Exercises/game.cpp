/*#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, r, a[2003], b[2003], ans = 0;

vector < pii > temp;

void back_track(int id) {
	for (int i = 1; i <= n; i++) b[i] = a[i];
		for (auto x : temp) {
		for (int i = x.fi; i <= x.se; i++) {
			if (b[i] == 0) return ;
			b[i] --;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res += (!b[i]);
	ans = max(ans, res);
	if (id == r + 1) return ;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			temp.push_back({i, j});
			back_track(id + 1);
			temp.pop_back();
		}
	}
}

int main() {
	fast;
	cin >> n >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	back_track(1);
	cout << ans;
}
*/


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

const string NAME = "";
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

ll n, r, a[203], dp[203][203];

pll pos[203][203];

int main() {
	fast;
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[i][i] = {i, 1};
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			if (a[i] == a[j]) pos[i][j] = {j, 2};
			else pos[i][j] = {(a[i] < a[j] ? i : j), 1};
			if (len > 2) {
				if (a[pos[i][j].fi] == a[pos[i + 1][j - 1].fi]) {
					pos[i][j].fi = max(pos[i][j].fi, pos[i + 1][j - 1].fi);
					pos[i][j].se += pos[i + 1][j - 1].se;
				}
				if (a[pos[i][j].fi] > a[pos[i + 1][j - 1].fi]) pos[i][j] = pos[i + 1][j - 1];
			}
		}
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= r; j++) dp[i][j] = -LINF;
	dp[0][0] = 0;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				int l = k;
				int sub = 0;
				int dem = 0;
				int pre = 0;
				while (l <= i) {
					//if (i == 1 && j == 0) cout << dem << " " << a[pos[l][i].fi] << " " << pre << '\n';
					if (dem + a[pos[l][i].fi] - pre > j) break;
					//if (i == 6 && j == 2 && k == 1) cout << l << " " << i << " " << pos[l][i].fi << " " << pos[l][i].se << '\n';
					dem += a[pos[l][i].fi] - pre;
					sub += pos[l][i].se;
					pre = a[pos[l][i].fi];
					l = pos[l][i].fi + 1;
				}	
				dp[i][j] = max(dp[i][j], dp[k - 1][j - dem] + sub);
				res = max(res, dp[i][j]);
			}
			cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << res;
}
