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

ll m, dp[(1 << 14)], pow_base[100003], b[14];

string s, a[14];

int main() {
	fast;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		ll &temp = b[i];
		temp = 0;
		for (auto x : a[i]) 
			temp = (temp * base + x) % MOD;
	}
	pow_base[0] = 1;
	for (int i = 1; i <= n; i++) 
		pow_base[i] = 	

}
