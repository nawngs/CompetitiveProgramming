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

string s;

int n, g[26][26], G[4][4][1 << 7][1 << 7], dp[303][303];

void prepare() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int len1 = (i < 3 ? 7 : 5);
			int len2 = (j < 3 ? 7 : 5);
			for (int mask1 = 0; mask1 < (1 << len1); mask1++) 
				for (int mask2 = 0; mask2 < (1 << len2); mask2++)
					for (int bit1 = 0; bit1 < len1; bit1++) {
						if (((mask1 >> bit1) & 1)) 
						for (int bit2 = 0; bit2 < len2; bit2++) 
							if (((mask2 >> bit2) & 1))
								G[i][j][mask1][mask2] |= g[i * 7 + bit1][j * 7 + bit2];
					}
		}
}

int main() {
	fast;
	//fre();
	cin >> s >> n;
	for (int i = 1; i <= n; i++) {
		string t;
        getline(cin >> ws, t);
        g[t[2]-'a'][t[3]-'a'] |= 1<<(t[0]-'a');
	}
	prepare();
	for (int i = 0; i < (int)s.size(); i++)
		dp[i][i] = (1 << (s[i] - 'a'));
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < (int)s.size(); j++) {
			for (int k = i; k < j; k++) {
				for (int set1 = 0; set1 < 4; set1++)
					for (int set2 = 0; set2 < 4; set2++) {
						int len1 = (set1 < 3 ? 7 : 5);
						int len2 = (set2 < 3 ? 7 : 5);
						dp[i][j] |= G[set1][set2][((dp[i][k] >> (set1 * 7)) & ((1 << len1) - 1))]
												 [((dp[k + 1][j] >> (set2 * 7)) & ((1 << len2) - 1))];
					}
			}
		}
	}
	if (dp[0][s.size() - 1] == 0) {
		cout << "No Solution." << '\n';
		return 0;
	}
	for (int i = 0; i <= 25; i++) {
		if ((dp[0][s.size() - 1] >> i) & 1) 
			cout << char(i + 'a');
	}
}
