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

string s1, s2;

void sol() {
	cin >> s2 >> s1;
	string ans = "";
	int i1 = s1.size() - 1, i2 = s2.size() - 1;
	while (1) {
		if (i2 == -1) break;
		if (i1 < i2) {
			cout << -1 << '\n';
			return ;
		}
		if (s1[i1] >= s2[i2]) {
			char c = '0' + s1[i1] - s2[i2];
			ans = c + ans;
			i1 --;
			i2 --;
		}
		else {
			if (i1 == 0 || s1[i1 - 1] != '1') {
				cout << -1 << '\n';
				return ;
			}
			char c = '0' + 10 + s1[i1] - s2[i2];
			ans = c + ans;
			i1 -= 2;
			i2 --; 
		}
	}
	for (int i = i1; i >= 0; i--) ans = s1[i] + ans;
	int pos = ans.size() - 1;
	for (int i = 0; i < ans.size(); i++) 
		if (ans[i] != '0') {
			pos = i;
			break;
		}
	for (int i = pos; i < ans.size(); i++) cout << ans[i];
	cout << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
