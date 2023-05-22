#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

struct PrefixSum2d {
	int s1, cnt;
	ll s2;
} dp[1515][1515];

int n, m, cnt_color[300003], cnt_ex[300003];

vector < int > vec[300003];

void update(int const &a, int const &b, int const &c, int const &d, ll const &id) {
	dp[a][b].cnt ++;
	dp[a][d + 1].cnt --;
	dp[c + 1][b].cnt --;
	dp[c + 1][d + 1].cnt ++;
	dp[a][b].s1 += id;
	dp[a][d + 1].s1 -= id;
	dp[c + 1][b].s1 -= id;
	dp[c + 1][d + 1].s1 += id;
	ll tam = id * id;
	dp[a][b].s2 += tam;
	dp[a][d + 1].s2 -= tam;
	dp[c + 1][b].s2 -= tam;
	dp[c + 1][d + 1].s2 += tam;
}	

void sol() {
	cin >> n >> m;
	for (int i = 0; i <= m + 6; i++)
		for (int j = 0; j <= m + 6; j++) dp[i][j].cnt = dp[i][j].s1 = dp[i][j].s2 = 0;
	for (int i = 1; i <= n; i++) {
		vec[i].clear();
		cnt_ex[i] = cnt_color[i] = 0;
		int xl, xr, yl, yr;
		cin >> xl >> xr >> yl >> yr;
		update(xl, yl, xr, yr, i);
	}
	int dem = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j].cnt = dp[i][j - 1].cnt + dp[i - 1][j].cnt - dp[i - 1][j - 1].cnt + dp[i][j].cnt;
			dp[i][j].s1 = dp[i][j - 1].s1 + dp[i - 1][j].s1 - dp[i - 1][j - 1].s1 + dp[i][j].s1;
			dp[i][j].s2 = dp[i][j - 1].s2 + dp[i - 1][j].s2 - dp[i - 1][j - 1].s2 + dp[i][j].s2;
			int cur = dp[i][j].cnt;
			int cur_s1 = dp[i][j].s1;
			ll cur_s2 = dp[i][j].s2;
			dem += (cur > 0);
			if (cur == 1) cnt_color[cur_s1] ++;
			if (cur == 2) {
				ll tam = (cur_s1 * cur_s1 - cur_s2);	
				ll hieu = sqrtl(cur_s2 - tam);
				ll a = (cur_s1 + hieu) / 2;
				ll b = cur_s1 - a;
				vec[a].push_back(b);
			}
		}
	int res = dem;
	for (int i = 1; i <= n; i++) {
		for (auto x : vec[i]) {
			cnt_ex[x] ++;
			res = min(res, dem - cnt_color[i] - cnt_color[x] - cnt_ex[x]);
		}
		for (auto x : vec[i]) cnt_ex[x] --;
	}
	int temp[2] = {0, 0};
	for (int i = 1; i <= n; i++) {
		temp[0] = max(temp[0], cnt_color[i]);
		if (temp[0] > temp[1]) swap(temp[1], temp[0]);
 	}
	cout << min(res, dem - temp[0] - temp[1]) << '\n';
}

signed main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
