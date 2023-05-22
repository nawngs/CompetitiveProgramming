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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, cnt[5005][5005], res = 0;

vector < ll > hashs[5003];

void solve1() {
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) ans += cnt[i][j];
	cout << ans;
}

void backtrack(int pos, int pre) {
	
}

void solve2() {
	backtrack(1, 0);
	cout << res;
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		s = ' ' + s;
		hashs[i].push_back(0);
		for (int j = 1; j < s.size(); j++) hashs[i].push_back((hash[i][j - 1] * base + s[j]) % MOD);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int l = 1, r = min(hashs[i].size(), hashs[j].size()) - 1, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (hashs[i][mid] == hashs[j][mid]) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			cnt[i][j] = ans;
		}
	}
	if (k == n) solve1();
	if (n <= 20) solve2();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
