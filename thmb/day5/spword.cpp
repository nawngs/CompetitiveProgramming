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

string s;

int z[1000003], cnt[1000003];

bool check[1000003];

int main() {
	fast;
	//fre();
	cin >> s;
	s = ' ' + s;
	z[1] = 0;
	int l = 0, r = 0;
	cnt[1] = 1;
	for (int i = 2; i < s.size(); i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x < s.size() && s[i + x] == s[x + 1]) {
			x++;
			l = i;
			r = i + x - 1;
		}
		cnt[1] ++;
		cnt[z[i] + 1] --;
		if (i + z[i] == s.size()) check[z[i]] = 1;
	}
	for (int i = 2; i < s.size(); i++) cnt[i] += cnt[i - 1];
	for (int i = s.size() - 1; i >= 1; i--) {
		if (cnt[i] >= 3 && check[i]) {
			for (int j = 1; j <= i; j++) cout << s[j];
			return 0;
		}
	}
	cout << "No solution!";
}
