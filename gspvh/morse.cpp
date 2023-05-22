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

const string NAME = "morse";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const string CODES[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};


void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s;

int dp[900003][2], trace[900003][2];

// dp[i][0] la co ki tu tai i
// dp[i][1] la ket thuc = |

bool getmin(int &x, int y) {
	if (x > y) {
		x = y;
		return true;
	}
	else return false;
}

int main() {
	fast;
	//fre();
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 0; i <= n; i++) dp[i][1] = dp[i][0] = INF;
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		if (getmin(dp[i + 1][1], dp[i][0] + (s[i + 1] != '|'))) trace[i + 1][1] = 1;
		if (i + 2 <= n && getmin(dp[i + 2][1], dp[i][0] + (s[i + 1] != '|') + (s[i + 2] != '|'))) trace[i + 2][1] = 2;
		if (dp[i][1] != INF) {
			for (int j = 0; j <= ('z' - 'a'); j++) {
				if (i + CODES[j].size() <= n) {
					int total = 0;
					for (int t = 0; t < CODES[j].size(); t++) total += (s[i + t + 1] != CODES[j][t]);
					if (getmin(dp[i + CODES[j].size()][0], dp[i][1] + total)) trace[i + CODES[j].size()][0] = j;
				}
			}
		}
	}
	cout << dp[n][0] << '\n';
	string res = "";
	int i = n, j = 0;
	while (i > 0) {
		int k = trace[i][j];
		if (j == 0) {
			string tmp = CODES[k];
			reverse(tmp.begin(), tmp.end());
			res += tmp;
			i -= CODES[k].size();
			j = 1;
		}
		else {
			for (int t = 0; t < k; t++) res += '|';
			i -= k;
			j = 0;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
}
