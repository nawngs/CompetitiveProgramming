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

string a, b, s;

int z[2000003];

int main() {
	fast;
	cin >> a >> b;
	s = ' ' + a + '#' + b;
	z[1] = 0;
	int l = 0, r = 0;
	for (int i = 2; i < s.size(); i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x < s.size() && s[i + x] == s[x + 1]) {
			x++;
			l = i;
			r = i + x - 1;
		}
	}
	vector < int > res;
	for (int i = 1; i < s.size(); i++) if (z[i] == a.size()) res.push_back(i);
	cout << res.size() << '\n';
	for (auto x : res) cout << x - a.size() - 1 << " ";
}
