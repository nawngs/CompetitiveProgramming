#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s1, s2, s;

int res[203];

void dequy(int pos, int i1, int i2) {
	if (pos == s.size()) {
		for (int i = 0; i < pos; i++) cout << res[i];
		exit(0);
	}
	if (i1 < s1.size() && s1[i1] == s[pos]) {
		res[pos] = 1;
		dequy(pos + 1, i1 + 1, i2);
	}
	if (i2 < s2.size() && s2[i2] == s[pos]) {
		res[pos] = 2;
		dequy(pos + 1, i1, i2 + 1);
	}
}

void sol() {
	cin >> s1 >> s2 >> s;
	dequy(0, 0, 0);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
