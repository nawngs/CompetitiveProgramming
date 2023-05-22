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

int n, res = 0, cnt[2000003], dp[2000003];

vector < int > a;

void sol() {
	cin >> n;
	a.clear();
	res = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x > 2 * n) res ++;
		else a.push_back(x);
	}
	for (int i = 0; i <= 2 * n; i++) {
		cnt[i] = 0;
		dp[i] = 0;
	}
	for (auto x : a) cnt[x] ++;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 2 * n / i; j >= 0; j--) {
			int tam = dp[j] + abs(j - cnt[i]);
			if (i == 2 * n && j == 0) {
				cout << res + tam << '\n';
				return ;
			}
			dp[j] = tam;
			if (j < 2 * n / i) dp[j] = min(dp[j], dp[j + 1]);
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
