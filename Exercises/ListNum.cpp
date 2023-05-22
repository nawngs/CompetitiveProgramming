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

const string NAME = "listnum";
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

int n;

string s[1003];

bool compare(string x, string y) {
	if (y.size() > x.size()) return false;
	if (y.size() < x.size()) return true;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] > y[i]) return true;
		if (x[i] < y[i]) return false;
	}
	return false;
}

int main() {
	fast;
	fre();
	cin >> n;
	s[0] = '0';
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++) {
		bool valid = 1;
		for (auto c : s[i]) 
			if (c == '?') valid = 0; 
		if ((valid && !compare(s[i], s[i - 1])) || (s[i - 1].size() > s[i].size())) {
			cout << "IMPOSSIBLE" << '\n';
			return 0;
		}
		if (valid) continue;
		if (s[i].size() > s[i - 1].size()) {
			if (s[i][0] == '?') s[i][0] = '1';
			for (int j = 0; j < s[i].size(); j++)
				if (s[i][j] == '?') s[i][j] = '0';
		}
		else {
			int cmp = 0, pos = 0; // 0 la dang =, 1 la s[i] > s[i - 1], 2 la s[i] < s[i - 1]
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == '?') continue;
				if (s[i][j] > s[i - 1][j]) {
					cmp = 1;
					pos = j;
					break;
				}
				if (s[i][j] < s[i - 1][j]) {
					pos = j;
					cmp = 2;
					break;
				}
			}
			if (cmp == 1) {
				for (int j = 0; j < s[i].size(); j++)
					if (s[i][j] == '?') {
						if (j < pos) s[i][j] = s[i - 1][j];
						else s[i][j] = '0';
					}
			}
			if (cmp == 0) {
				bool changed = 0;
				for (int j = s[i].size() - 1; j >= 0; j--) {
					if (s[i][j] == '?') {
						if (s[i - 1][j] == '9' && !changed) {
							s[i][j] = '0';
							continue;
						}
						if (changed) s[i][j] = s[i - 1][j];
						else {
							s[i][j] = s[i - 1][j] + 1;
							changed = 1;
						}
					}
				}
				if (!changed) {
					cout << "IMPOSSIBLE" << '\n';
					return 0;
				}
			}
			if (cmp == 2) {
				bool changed = 0;
				for (int j = pos - 1; j >= 0; j--) {
					if (s[i][j] == '?') {
						if (s[i - 1][j] == '9' && !changed) {
							s[i][j] = '0';
							continue;
						}
						if (changed) s[i][j] = s[i - 1][j];
						else {
							s[i][j] = s[i - 1][j] + 1;
							changed = 1;
						}
					}
				}
				if (!changed) {
					cout << "IMPOSSIBLE" << '\n';
					return 0;
				}
				for (int j = pos + 1; j < s[i].size(); j++) 
					if (s[i][j] == '?')
						s[i][j] = '0'; 
				}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << s[i] << '\n';
}
 