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

int n;

string s[500005];

map < string, bool > check;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		if ((i > 1 && s[i][0] != s[i - 1][s[i - 1].size() - 1]) || check[s[i]]) {
			cout << "NO" << '\n' << i << '\n';
			return ;
		}
		check[s[i]] = true;
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
