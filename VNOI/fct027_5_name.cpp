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

int n;


char get_uppercase(char x) {
	if ('A' <= x && x <= 'Z') return x;
	return (char) x - 32;
}

char get_lowercase(char x) {
	return (char) get_uppercase(x) + 32;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s, ans = "";
		getline(cin, s, '\n');
		s = ' ' + s;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == ' ' && s[i - 1] != ' ') ans = ans + ' ';
			if (s[i] != ' ') {
				if (s[i - 1] == ' ') ans += get_uppercase(s[i]);
				else ans += get_lowercase(s[i]);
			}
		}
		if (ans != "") cout << ans << '\n'; 
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
