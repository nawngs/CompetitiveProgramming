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

string s;

void sol() {
	cin >> n >> s;
	int pos = s.size() - 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] > s[i - 1]) {
			pos = i - 1;
			break;
		}
	}
	if (s[0] == s[1]) cout << s[0] << s[0];
	else {
		for (int i = 0; i <= pos; i++) cout << s[i];
		for (int i = pos; i >= 0; i--) cout << s[i];
	}
	cout << '\n';
}; 

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
