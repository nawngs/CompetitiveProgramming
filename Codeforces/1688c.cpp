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

int n, cnt[30];

void sol() {
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n * 2 + 1; i++) {
		string s;
		cin >> s;
		for (auto c : s) cnt[c - 'a'] ++;
	}
	for (int i = 0; i <= 'z' - 'a'; i++) {
		if (cnt[i] % 2 == 1) {
			char c = i + 'a';
			cout << c << '\n';
			return ;
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
