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

ll n, res = 0;

bitset < 3001 > s[3001], tam;

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			s[i][j] = (c - '0');
		}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (s[i][j] == 1) {
				tam = s[i] & s[j];
				res += 1ll * tam.count();
			}
		}
	}
	cout << res / 3;
}
