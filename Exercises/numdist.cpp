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

int n;

string s[100003];

map < string, int > f;

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		while (s[i].size() < 8) s[i] = '0' + s[i];
	}
	sort(s + 1, s + n + 1);
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {

	}
}
