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

const string NAME = "bits";
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

string s, t;

void sol() {
	cin >> s >> t;
	int res = 0, dem1 = 0, dem2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0' && t[i] == '1') dem1 ++;
		if (s[i] == '1' && t[i] == '0') dem2 ++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			res ++;
			if (t[i] == '1' && dem1 < dem2) dem1 ++;
		}
	}
	if (dem2 > dem1) cout << -1;
	else cout << res + dem1;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
