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

const string NAME = "StrSame";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 1e5 + 3;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s;

int cnt[200003][26];

map < vector < int >, int > f;

vector < int > digit;

void sol() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j];
		cnt[i][s[i] - 'a'] ++;
		if (cnt[i][s[i] - 'a'] == 1) digit.push_back(s[i] - 'a');
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		int temp = MOD;
		for (auto x : digit) temp = min(temp, cnt[i][x]);
		vector < int > tam;
		tam.clear();
		for (auto x : digit) tam.push_back(cnt[i][x] - temp);
		ans += 1ll * f[tam];
		f[tam] ++;
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
