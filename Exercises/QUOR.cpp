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

ll n, D, a[203], dp[203][1003][503], together[203], all[203], alone[203];

ll add(ll &x, ll y) {
	x = (x + y) % MOD;
	return x;
}

int main() {
	fast;
	cin >> n >> D;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[1][0][a[1]] = 1;
	all[1] = alone[1] = 1;
	together[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= D; j++) {
			for (int mina = 1; mina <= 500; mina++) {
				if (dp[i][j][mina] == 0) continue;
				if (j + (a[i + 1] - mina) <= D) {
					add(dp[i + 1][j + (a[i + 1] - mina)][mina], dp[i][j][mina]);
					add(together[i + 1], dp[i][j][mina]);
				}
				add(dp[i + 1][j][mina], dp[i][j][mina]);
			}
		}
		alone[i + 1] = all[i];
		all[i + 1] = (alone[i + 1] + together[i + 1]) % MOD;
	}
	cout << all[n];
}
