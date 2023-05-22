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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string n, s;

bool check(string a, string b) {
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) return 0;
		if (a[i] > b[i]) return 1;
	}
	return 1;
}

int main() {
	fast;
	//fre();
	cin >> n >> s;
	if (!check(n, s)) {
		cout << "";
		return 0;
	}
	int sze = 0, len = s.size();
	while (!n.empty()) {
		bool choose_same = false;
		string new_n = "";
		for (auto c : n) {
			if (!choose_same && c == s[0]) choose_same = 1;
			else new_n += c;
		}
		if (choose_same) {
			string news = s;
			news.erase(news.begin());
			if (check(new_n, news)) {
				cout << s[0];
				n = new_n;
				s = news;
				continue;
			}
		}
		char dg = '9';
		for (auto c : n) 
			if (c > s[0]) dg = min(dg, c);
		cout << dg;
		bool deleted = false;
		new_n = "";
		for (auto c : n) {
			if (!deleted && c == dg) deleted = 1;
			else new_n += c;
		}
		sort(new_n.begin(), new_n.end());
		for (auto c : new_n) cout << c;
		return 0;
	}
}
