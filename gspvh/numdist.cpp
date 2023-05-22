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

const string NAME = "numdist";
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

ll n, cnt[10][12];

vector < ll > digit;

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		digit.clear();
		for (int j = s.size() - 1; j >= 0; j--) digit.push_back(s[j] - '0');
		while (digit.size() < 9) digit.push_back(0);
		for (int j = 0; j < digit.size(); j++) cnt[digit.size() - j][digit[j]] ++;
	}
	ll res = 0;
	for (int i = 1; i < 10; i++) {
		ll total = (n * (n - 1)) / 2, s = 0;
		bool th = false;
		for (int j = 0; j <= 9; j++) {
			s += (cnt[i][j] * (cnt[i][j] - 1)) / 2;
			if (cnt[i][j] != 0) th = 1;
		}
		if (!th) break;
		total -= s;
		res = (res + total) % MOD;
	}
	cout << res << '\n';
}
