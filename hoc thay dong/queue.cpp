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

ll n, a[2003], C[2003][2003], f[2003][2003], p, q;

int main() {
	fast;
	//fre();
	cin >> n >> p >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	  for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
        	if (i < j) C[i][j] = 0;
            else if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            //cout << i << " " << j << " " << C[i][j] << '\n';
        }
    }
    f[0][0] = 1;
  	for (int i = 0; i < n; i++)
  		for (int j = 0; j <= i; j++) {
  			f[i + 1][j] = (f[i + 1][j] + f[i][j] * i) % MOD;
  			f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % MOD; 
  		}
  	ll res = 0;
  	for (int i = 1; i <= n; i++) res = (res + ((C[n - 1][i - 1] * f[i - 1][p - 1]) % MOD) * f[n - i][q - 1]) % MOD;
  	cout << res;
}
