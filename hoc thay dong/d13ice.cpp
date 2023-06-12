#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
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
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, cnt[5003][5003];

string s[5003];

int main() {
	fast;
	cin >> n;
	queue < piii > que;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == '0') continue;
			for (int k = 0; k < 4; k++) {
				int newi = i + dx[k];
				int newj = j + dy[k];
				if (newi < 1 || newj < 1 || newi > n || newj > n || s[newi][newj] == '1') continue;
				cnt[i][j] ++;
				que.push({{i, j}, 1}); 
			}
		}
	}
	int res = 0;
	while (que.size()) {
		auto u = que.front();
		que.pop();
		int i = u.fi.fi, j = u.fi.se;
		res = u.se;
		for (int k = 0; k < 4; k++) {
			int newi = i + dx[k];
			int newj = j + dy[k];
			if (newi < 1 || newj < 1 || newi > n || newj > n || s[newi][newj] == '0') continue;
			cnt[newi][newj] ++;
			if (cnt[newi][newj] == 2) que.push({{newi, newj}, u.se + 1}); 
		}
	}
	cout << res;
}
