#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "brentford40mu";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	ll cnt, suma, sumb, sub;
} dp[1000003][4];

string a, b;

void add(Data &x, Data const &y, int const &dga, int const &dgb) {
	if (y.cnt == 0) return ;
	x.cnt = (x.cnt + y.cnt) % MOD;
	x.suma = (x.suma + (y.suma * 10 + y.cnt * dga)) % MOD;
	x.sumb = (x.sumb + (y.sumb * 10 + y.cnt * dgb)) % MOD;
	x.sub = (x.sub + (y.sub * 100) + dga * y.sumb * 10 + dgb * y.suma * 10 + y.cnt * dga * dgb) % MOD;
}

int main() {
	fast;
	//fre();
	cin >> a >> b;
	int n = a.size();
	a = ' ' + a;
	b = ' ' + b;
	dp[0][0].cnt = 1;
	dp[0][0].suma = dp[0][0].sumb = dp[0][0].sub = 0;
	for (int i = 1; i <= n; i++) {
		for (int dga = (a[i] == '?' ? 0 : a[i] - '0'); dga <= (a[i] == '?' ? 9 : a[i] - '0'); dga++) {
			for (int dgb = (b[i] == '?' ? 0 : b[i] - '0'); dgb <= (b[i] == '?' ? 9 : b[i] - '0'); dgb++) {
				if (dga == dgb) {
					add(dp[i][0], dp[i - 1][0], dga, dgb);
					add(dp[i][1], dp[i - 1][1], dga, dgb);
					add(dp[i][2], dp[i - 1][2], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
				}
				if (dga > dgb) {
					add(dp[i][1], dp[i - 1][1], dga, dgb);
					add(dp[i][1], dp[i - 1][0], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
					add(dp[i][3], dp[i - 1][2], dga, dgb);
				}
				if (dgb > dga) {
					add(dp[i][2], dp[i - 1][2], dga, dgb);
					add(dp[i][2], dp[i - 1][0], dga, dgb);
					add(dp[i][3], dp[i - 1][3], dga, dgb);
					add(dp[i][3], dp[i - 1][1], dga, dgb);
				}
			}
		}
	}
	cout << dp[n][3].sub << '\n';
}