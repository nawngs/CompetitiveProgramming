#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
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

int n, dp[256][26];

string s, a[1003];

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return 1;
	}
	return false;
}

int main() {
	fast;
	//fre();
	cin >> s;
	cin >> n;
	s += '#';
	for (int i = 0; i < (int)s.size(); i++)
		for (int j = 0; j < 26; j++) dp[i][j] = INF;
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int cur = -1;
		for (auto c : a[i]) 
			if (c == s[cur + 1]) {
				cur ++;
			}
		if (cur != -1) {
			dp[cur][a[i].back() - 'a'] = min(dp[cur][a[i].back() - 'a'], (int)a[i].size());
			heap.push({dp[cur][a[i].back() - 'a'], {cur, a[i].back() - 'a'}});
		}
	}
	int res = INF;
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		int i = u.se.fi, j = u.se.se;
		if (u.fi != dp[i][j]) continue;
		if (i == (int)s.size() - 2) res = min(res, dp[i][j]);
			for (int k = 1; k <= n; k++) {
				if (j == a[k][0] - 'a') {
					int cur = i;
					for (int p = 1; p < (int)a[k].size(); p++) {
						char c = a[k][p];
						if (c == s[cur + 1]) cur ++;
					}   
					if (minimize(dp[cur][a[k].back() - 'a'], dp[i][j] + (int)a[k].size() - 1))
						heap.push({dp[cur][a[k].back() - 'a'], {cur, a[k].back() - 'a'}});
				}
			}
	}
	cout << (res == INF ? -1 : res);
}
