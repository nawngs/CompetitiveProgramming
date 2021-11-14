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

string s, t;

ll f[35];

void sol() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) f[s[i] - 'a'] = i;
	cin >> t;
	long long ans = 0;
	for (int i = 1; i < t.size(); i++) ans += abs(f[t[i] - 'a'] - f[t[i - 1] - 'a']);
	cout << ans << '\n'	; 
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
