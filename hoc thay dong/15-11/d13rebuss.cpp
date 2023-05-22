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

int dp[53][2];

int start1, start2, startrs;

string s1, s2, rs;

void add(int &u, const int &v) {
	u += v;
	if (u > MOD) u -= MOD;
}

int calc(int pos, int remember) {
	//cout << pos << " " << remember << '\n';
	if (pos == -1) return 1;
	if (dp[pos][remember] != -1) return dp[pos][remember];
	int &res = dp[pos][remember];
	res = 0;
	if (s1[pos] == '*') {
		for (int val1 = 0 + (pos == start1); val1 <= 9; val1++) {
			if (s2[pos] != '*') {
				int val2 = s2[pos] - '0';
				if (rs[pos] == '*') {
					if (startrs == pos && (val1 + val2 + remember) % 10 == 0) continue;
					add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
				}
				else {
					if ((val1 + val2 + remember) % 10 != rs[pos] - '0') continue;
					add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
				}
			}
			else {
				for (int val2 = 0 + (pos == start2); val2 <= 9; val2++) {
					if (rs[pos] == '*') {
						if (startrs == pos && (val1 + val2 + remember) % 10 == 0) continue;
						add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
					}
					else {
						if ((val1 + val2 + remember) % 10 != rs[pos] - '0') continue;
						add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
					}
				}
			}
		}
	}
	else {
		int val1 = s1[pos] - '0';
		if (s2[pos] != '*') {
			int val2 = s2[pos] - '0';
			if (rs[pos] == '*') {
				if (startrs == pos && (val1 + val2 + remember) % 10 == 0) return res;
				add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
			}
			else {
				if ((val1 + val2 + remember) % 10 != rs[pos] - '0') return res;
				add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
			}
		}
		else {
			for (int val2 = 0 + (pos == start2); val2 <= 9; val2++) {
				if (rs[pos] == '*') {
					if (startrs == pos && (val1 + val2 + remember) % 10 == 0) continue;
					add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
				}
				else {
					if ((val1 + val2 + remember) % 10 != rs[pos] - '0') continue;
					add(res, calc(pos - 1, (val1 + val2 + remember) >= 10));
				}
			}
		}
	}
	return res;
}

int main() {
	fast;
	//fre();
	cin >> s1 >> s2 >> rs;
	rs = '0' + rs;
	startrs = 1;
	while (s1.size() < rs.size()) {
		start1 ++;
		s1 = '0' + s1;
	}
	while (s2.size() < rs.size()) {
		start2 ++;
		s2 = '0' + s2;
	}
	memset(dp, 255, sizeof(dp));
	cout << calc(rs.size() - 1, 0) << '\n';
}
