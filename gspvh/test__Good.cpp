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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

const long long oo = 1e18;
long long n, a[200005], f[200005], res = -oo, dp[200005], pos;

void calc() {
	//cout << 1 << '\n';
	for(int i = 1; i <= n; i++) f[i] = n + 1;
	a[n + 1] = oo;
	a[0] = -oo;
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		long long l = 0, r = n, m, ans = -1;
		while(l <= r){
			m = (l + r) / 2;
			if(a[f[m]] < a[i]){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		dp[i] = f[ans];
		if(a[f[ans + 1]] > a[i]){
			f[ans + 1] = i;
			if(res < ans + 1){
				res = ans + 1;
				pos = i;
			}
		}
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	calc();
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			a[j] = -a[j];
			//cout << i << " " << j << '\n';
			calc();
			//if (res == 6) cout << i << " " << j << '\n';
		}
		for (int j = i; j <= n; j++) a[j] = -a[j];
	} 
	cout << res;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
