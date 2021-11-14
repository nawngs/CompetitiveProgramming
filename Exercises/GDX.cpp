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

const string NAME = "GDX";
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

int change(string s) {
	int cnt = 0;
	int n = s.size() - 1;
	for (int i = 0; i <= n; i++) {
		if (i > n - i) break;
		if (s[i] != s[n - i]) cnt ++;
	}
	return cnt;
}

void sol() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string tams = "";
		string tmps = "";
		for (int j = 0; j <= i; j++) tams = tams + s[j];
		for (int j = i + 1; j < s.size(); j++) tmps = tmps + s[j];
		if (change(tmps) <= 2 && change(tams) <= 2) {
			cout << 1 << '\n';
			return ;
		}
	}
	cout << 0 << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
