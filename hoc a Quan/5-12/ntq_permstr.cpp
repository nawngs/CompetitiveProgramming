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

int n, dp[403][403][403][3], cnt[403][3];

string s;

vector < int > pos[3];

map < char, int > f;

void minimize(int &x, int y) {
	if (x > y) x = y;
}

int main() {
	fast;
	//fre();
	cin >> n >> s;
	s = ' ' + s;
	f['R'] = 0; f['G'] = 1; f['Y'] = 2;
	for (int i = 1; i <= n; i++) 
		pos[f[s[i]]].push_back(i);
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < 3; j++) 
			cnt[i][j] = cnt[i + 1][j];
		cnt[i][f[s[i]]] ++;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;
	for (int i = 0; i <= pos[0].size(); i++) 
		for (int j = 0; j <= pos[1].size(); j++)
			for (int k = 0; k <= pos[2].size(); k++) {
				for (int last = 0; last < 3; last++) {
					if (dp[i][j][k][last] >= INF) continue;
					if (last != 0 && i < pos[0].size()) {
						int nxt = pos[0][i];
						int id1 = pos[1].size() - cnt[nxt][1];
						int id2 = pos[2].size() - cnt[nxt][2];
						minimize(dp[i + 1][j][k][0], dp[i][j][k][last] + nxt + max(0, j - id1) + max(0, k - id2) - i - j - k - 1); 
					}
					if (last != 1 && j < pos[1].size()) {
						int nxt = pos[1][j];
						int id0 = pos[0].size() - cnt[nxt][0];
						int id2 = pos[2].size() - cnt[nxt][2];
						minimize(dp[i][j + 1][k][1], dp[i][j][k][last] + nxt + max(0, i - id0) + max(0, k - id2) - i - j - k - 1);
					}
					if (last != 2 && k < pos[2].size()) {
						int nxt = pos[2][k];
						int id0 = pos[0].size() - cnt[nxt][0];
						int id1 = pos[1].size() - cnt[nxt][1];
						minimize(dp[i][j][k + 1][2], dp[i][j][k][last] + nxt + max(0, i - id0) + max(0, j - id1) - i - j - k - 1);
					} 
				}
			}
	int res = INF;
	for (int i = 0; i < 3; i++) 
		res = min(res, dp[pos[0].size()][pos[1].size()][pos[2].size()][i]);
	cout << (res == INF ? -1 : res);
}
