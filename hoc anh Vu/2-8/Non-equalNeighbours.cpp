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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], res = 1, f[200003][2], g[200003][2];

int main() {
	//fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st;
   	f[0][0] = 1;
    g[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()] > a[i]) st.pop();
		if (st.size()) {
			f[i][1] = (f[st.top()][1] + ((g[i - 1][0] - g[st.top() - 1][0]) * a[i])) % MOD;
			f[i][0] = (f[st.top()][0] + ((g[i - 1][1] - g[st.top() - 1][1]) * a[i])) % MOD;
		}
		else {
			f[i][1] = (g[i - 1][0] * a[i]) % MOD;
			f[i][0] = (g[i - 1][1] * a[i]) % MOD; 
		}
		//cout << i << " " << f[i][0] << " " << f[i][1] << '\n';
		g[i][0] = (g[i - 1][0] + f[i][0]) % MOD;
		g[i][1] = (g[i - 1][1] + f[i][1]) % MOD;
		st.push(i);
	}
	cout << (((f[n][n % 2] - f[n][!(n % 2)]) % MOD) + MOD) % MOD;
}
