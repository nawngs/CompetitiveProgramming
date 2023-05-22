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

bool f1[30][55][55], f2[30][55][55];

int n, res[55][55];

string s1, s2;

pair < char, string > a[55];

int main() {
	fast;
	cin >> s1 >> s2 >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		string y = "";
		y += s[3];
		y += s[4];
		a[i] = {s[0], y};
	}
	for (int len = 1; len <= s1.size(); len++) {
		for (int i = 0; i < s1.size() - len + 1; i++) {
			int j = i + len - 1;
			if (i == j) f1[s1[i] -'a'][i][j] = 1;
			else {
				for (int k = i; k < j; k++) {
					for (int p = 1; p <= n; p++) {
						char c_change = a[p].fi;
						char c1 = a[p].se[0], c2 = a[p].se[1];
						if (f1[c1 - 'a'][i][k] && f1[c2 - 'a'][k + 1][j]) f1[c_change - 'a'][i][j] = 1;
					}
				}
			}
		}
	}
	for (int len = 1; len <= s2.size(); len++) {
		for (int i = 0; i < s2.size() - len + 1; i++) {
			int j = i + len - 1;
			if (i == j) f2[s2[i] -'a'][i][j] = 1;
			else {
				for (int k = i; k < j; k++) {
					for (int p = 1; p <= n; p++) {
						char c_change = a[p].fi;
						char c1 = a[p].se[0], c2 = a[p].se[1];
						if (f2[c1 - 'a'][i][k] && f2[c2 - 'a'][k + 1][j]) f2[c_change - 'a'][i][j] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i <= s1.size(); i++)
		for (int j = 0; j <= s2.size(); j++) res[i][j] = INF;
	res[0][0] = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (i == j && i == 0) continue;
			for (int i_ = i; i_ >= 0; i_ --) {
				for (int j_ = j; j_ >= 0; j_ --) {
					for (int c = 0; c <= 'z' - 'a'; c++) {	
						bool th1 = (i == 0 || f1[c][i_][i - 1]);
						bool th2 = (j == 0 || f2[c][j_][j - 1]);
						if (th1 && th2) res[i][j] = min(res[i][j], res[i_][j_] + 1);
					}
				}
			}
			//cout << i << " " << j << " " << res[i][j] << '\n';
		}
	}
	cout << (res[s1.size()][s2.size()] == INF ? -1 : res[s1.size()][s2.size()]);
}
