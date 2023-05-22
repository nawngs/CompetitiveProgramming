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

int n, f[123], cnt[123][123];

bool th[123];

string s;

void sol() {
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		f[s[i]] ++;
		if (i < s.size() - 1) cnt[s[i]][s[i + 1]] ++;
	}
	int q;
	cin >> q;
	while (q--) {
		string x;
		cin >> x;
		int ans = 0;
		for (int i = 0; i < x.size(); i++) ans += f[x[i]];
		for (int i = 0; i < x.size(); i++) {
			for (int j = i; j < x.size(); j++) {
				ans -= cnt[x[i]][x[j]];
				if (i != j) ans -= cnt[x[j]][x[i]];
			}
		}
		cout << ans << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
