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

string s;

void sol() {
	cin >> s;
	if (s.size() % 2 == 1) {
		cout << "NO" << '\n';
		return ;
	}
	int n = s.size();
	string s1 = "", s2 = "";
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) s1 += s[i];
		else s2 += s[i];
	}
	cout << (s1 == s2 ? "YES" : "NO") << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
