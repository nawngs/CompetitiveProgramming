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

const string NAME = "numbers";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll A, B, dp[20][12][12][2][2];

vector < int > dg;

ll f(int id, int pre1, int pre2, bool less, bool has1) {
	if (id == dg.size()) return has1;
	if (dp[id][pre1][pre2][less][has1] != -1) return dp[id][pre1][pre2][less][has1];
	ll res = 0;
	for (int i = 0; i <= 9; i++) 
		if (i != pre1 && i != pre2 && (less || (i <= dg[id]))) {
			bool new_has1 = (has1 || i != 0);
			res += f(id + 1, pre2, (new_has1 ? i : 10), (less || i < dg[id]), new_has1);
		}
	
	dp[id][pre1][pre2][less][has1] = res;
	return res;
}

ll calc(ll b) {
	if (b == -1) return -1;
	dg.clear();	
	while (b > 0) {
		dg.push_back(b % 10);
		b /= 10;
	}
	reverse(dg.begin(), dg.end());
	memset(dp, 255, sizeof(dp));
	return f(0, 10, 10, 0, 0);
}

int main() {
	fast;
	fre();
	cin >> A >> B;
	cout << calc(B) - calc(A - 1) << '\n';
}
	