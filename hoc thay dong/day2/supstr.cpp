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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n = 0, val[20][20], dp[(1 << 20)][21], trace[(1 << 20)][21], nn;

string s[20], ss[20];

bool getbit(int val, int pos) {
	return (val & (1 << pos));
}

void getmin(int &x, int y) {
	x = min(x, y);
	return ;
}

void readINP() {
	cin >> nn;
	for (int i = 0; i < nn; i++) cin >> ss[i];
	sort(ss, ss + nn, [&](string &x, string &y) {
		return x.size() < y.size();
	});
	for (int i = 0; i < nn; i++) {
		bool th = false;
		for (int j = i + 1; j < nn; j++) {
			for (int k = 0; k <= ss[j].size() - ss[i].size(); k++) {
				string tem = "";
				for (int p = 0; p < ss[i].size(); p++) tem += ss[j][k + p];
				if (tem == ss[i]) {
					th = 1;
					break;
				}
			}
			if (th) break;
		}
		if (!th) {
			s[n] = ss[i]; 
			n ++;
		}
		
	}
}

int main() {
	//fast;
	//fre();
	readINP();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			string tam1 = "", tam2 = "";
			for (int pos = 0; pos < min(s[i].size(), s[j].size()); pos++) {
				tam1 = s[i][s[i].size() - pos - 1] + tam1;
				tam2 += s[j][pos];
				 if (tam1 == tam2) val[i][j] = pos + 1;
			}
			//cout << i << " " << j << " " << val[i][j] << '\n';
		}
	}
	for (int bit = 0; bit < (1 << n); bit++)
		for (int last = 0; last < n; last++) dp[bit][last] = INF;
	for (int i = 0; i < n; i++) dp[(1 << i)][i] = s[i].size();
	for (int bit = 0; bit < (1 << n); bit++) {
		for (int last = 0; last < n; last++) {
			if (getbit(bit, last)) {
				for (int new_bit = 0; new_bit < n; new_bit++) {
					if (!getbit(bit, new_bit)) {
						getmin(dp[bit | (1 << new_bit)][new_bit], dp[bit][last] + s[new_bit].size() - val[last][new_bit]);
						if (dp[bit | (1 << new_bit)][new_bit] == dp[bit][last] + s[new_bit].size() - val[last][new_bit]) 
							trace[bit | (1 << new_bit)][new_bit] = last;
					}
				}
			}
			//cout << bit << " " << last << ' ' << dp[bit][last] << '\n';
		}
	}
	int len = INF, pos = -1;
	for (int i = 0; i < n; i++) {
		if (dp[(1 << n) - 1][i] < len) pos = i;
		getmin(len, dp[(1 << n) - 1][i]);
	}
	int suff = -1, cur = (1 << n) - 1;
	string res = "";
	while (cur != 0) {
		//cout << pos << " " << suff << " " << res << '\n';
		if (suff == -1) res += s[pos];
		else for (int i = s[pos].size() - val[pos][suff] - 1; i >= 0; i--) res = s[pos][i] + res;
		suff = pos;
		pos = trace[cur][pos];
		cur -= (1 << suff);
	}
	cout << res;
}
 