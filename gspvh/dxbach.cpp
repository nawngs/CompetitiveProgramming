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

const string NAME = "dxbach";
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

ll type, n, k, dp[19][172][2], ans = 0;

bool has1 = 0;

vector < ll > digitn, digitk;

ll calc(int pos, int cur, bool less) {
	if (pos == (int)digitn.size()) return (cur == 0);
	if (dp[pos][cur][less] != -1) return dp[pos][cur][less];
	ll res = 0;
	for (int dg = 0; dg <= min(9, cur); dg++) 
		if (dg <= digitn[pos] || less) 
			res += calc(pos + 1, cur - dg, (less || dg < digitn[pos]));
	dp[pos][cur][less] = res;
	return res;
}

void find_res(int pos, int cur, bool less) {
	if (pos == (int)digitk.size()) return ;
	for (int dg = 0; dg < digitk[pos]; dg++)
		ans += calc(pos + 1, cur - dg, less || (dg < digitn[pos]));
	find_res(pos + 1, cur - digitk[pos], (less || digitk[pos] < digitn[pos]));
}

void solve0() {
	ll x = n, s = 0;
	digitn.clear();
	while (x > 0) {
		digitn.push_back(x % 10);
		x /= 10;
	}
	digitk.clear();
	x = k;
	while (x > 0) {
		digitk.push_back(x % 10);
		s += x % 10;
		x /= 10;
	}
	while (digitk.size() < digitn.size()) digitk.push_back(0);
	reverse(digitn.begin(), digitn.end());
	reverse(digitk.begin(), digitk.end());
	ans = 0;
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i < s; i++) {
		ans += calc(0, i, 0);
	}
	find_res(0, s, 0);
	cout << ans + 1 << '\n';
}

void solve(int pos, int cur, bool less, int num) {
	if (pos == (int)digitn.size()) return ;
	for (int dg = 0; dg <= min(9, cur); dg++) 
		if (dg <= digitn[pos] || less) {
			ll tam = calc(pos + 1, cur - dg, less || dg < digitn[pos]);
			if (num > tam) num -= tam;
			else {
				if (dg != 0) has1 = 1;
				if (has1) cout << dg;
				solve(pos + 1, cur - dg, less || dg < digitn[pos], num);
				return ;
			}
		}
}

void solve1() {
	ll x = n;
	digitn.clear();
	while (x > 0) {
		digitn.push_back(x % 10);
		x /= 10;
	}
	ll cur = 0;
	reverse(digitn.begin(), digitn.end());
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= 9 * 18; i++) {
		cur += calc(0, i, 0);
		if (cur >= k) {
			cur -= calc(0, i, 0);
			has1 = 0;
			solve(0, i, 0, k - cur);
			cout << '\n';
			return ;
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) {
		cin >> type >> n >> k;
		if (!type) solve0(); // vi tri so k
		else solve1(); // so thu k
	}
}
