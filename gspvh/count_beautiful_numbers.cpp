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

ll A, B, dp[20][4][2];

vector < int > dg;

ll f(int pos, int cnt, bool less) {
	if (pos == (int) dg.size()) return 1;
	if (dp[pos][cnt][less] != -1) return dp[pos][cnt][less];
	ll &res = dp[pos][cnt][less];
	res = 0;
	for (int i = 0; i <= 9; i++) 
		if ((i <= dg[pos]) || less) {
			int new_cnt = cnt;
			new_cnt += (i != 0);
			if (new_cnt > 3) continue;
			res += f(pos + 1, new_cnt, ((i < dg[pos]) || less));
		}
	return res;
}

ll calc(ll x) {
	dg.clear();
	while (x > 0) {
		dg.push_back(x % 10);
		x /= 10;
	}
	reverse(dg.begin(), dg.end());
	memset(dp, 255, sizeof(dp));
	return f(0, 0, 0);
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		cin >> A >> B;
		cout << calc(B) - calc(A - 1) << '\n';
	}
}
