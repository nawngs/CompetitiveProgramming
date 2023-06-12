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

ll n, m, dp[103][103];

vector < vector < ll > > a;

int main() {
	//fast;
	//fre();
	cin >> n >> m;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
	a.resize(m);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		a[i].resize(k);
		for (auto &x : a[i]) cin >> x;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += dp[n][i];
	for (int i = 1; i < (1 << m); i++) {
		vector < int > temp;
		for (int bit = 0; bit < m; bit++) 
			if ((i >> bit) & 1) 
				for (auto x : a[bit]) 
					temp.push_back(x);
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		int cur = n - temp.size() + 1;
		for (int j = 1; j <= cur; j++) {
			if (__builtin_popcount(i) % 2 == 1) res -= dp[cur][j];
			else res += dp[cur][j];
		}
	}
	cout << res;
}
