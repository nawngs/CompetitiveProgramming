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

string s1, s2;

void change(int l, int r) {
	string news = "";
	for (int i = l; i <= r; i++) news += s1[i];
	reverse(news.begin(), news.end());
	for (int i = l; i <= r; i++) s1[i] = news[i - l];
}

void sol() {
	cin >> s1 >> s2;
	int n = s1.size();
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	for (int i = 1; i <= n; i++) {
		if (s1[i] == s2[i]) continue;
		int pos = -1;
		for (int j = i + 1; j <= n; j++) {
			if (s1[j] == s2[i]) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			cout << "Different" << '\n';
			return ;
		}
		change(i, pos);
		cout << s1 << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
