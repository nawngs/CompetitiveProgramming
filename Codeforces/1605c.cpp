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

struct  Data {
	int index, cntb, cntc;
	Data(int _index, int _cntb, int _cntc) : index(_index), cntb(_cntb), cntc(_cntc) {};
};

vector < Data > posa;

int n;

string s;

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	posa.clear();
	int cntb = 0, cntc = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'a') posa.push_back({i, cntb, cntc});
		if (s[i] == 'b') cntb ++;
		if (s[i] == 'c') cntc ++;
	}
	int ans = 1e9 + 7;
	for (int i = 1; i < posa.size(); i++) {
		if (posa[i].cntb - posa[i - 1].cntb < 2 && posa[i].cntc - posa[i - 1].cntc < 2) ans = min(ans, posa[i].index - posa[i - 1].index + 1);
	}
	for (int i = 2; i < posa.size(); i++) {
		if (posa[i].cntb - posa[i - 2].cntb < 3 && posa[i].cntc - posa[i - 2].cntc < 3) ans = min(ans, posa[i].index - posa[i - 2].index + 1);
	}
	cout << (ans == 1e9 + 7 ? -1 : ans) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}