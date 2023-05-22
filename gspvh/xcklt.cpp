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

const string NAME = "xcklt";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 3e3;
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

string a, b, c;

short int dp[1003][503][503];

bool trace1[1003][503][503], trace2[1003][503][503];

int main() {
	fast;
	//fre();
	cin >> a >> b >> c;
	int lena = a.size(), lenb = b.size(), lenc = c.size();
	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;
	a += '#';
	b += '$';
	c += '%';
	for (int i = 0; i <= lena + lenb; i++)
		for (int j = 0; j <= lena; j++)
			for (int k = 0; k <= lenb; k++) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = 0; i <= lena + lenb; i++)
		for (int j = 0; j <= lena; j++)
			for (int k = 0; k <= lenb; k++) {
				if (dp[i][j][k] == INF) continue;
				if (dp[i + 1][j + 1][k + (a[j + 1] == b[k + 1])] > dp[i][j][k] + (a[j + 1] == c[dp[i][j][k] + 1])) {
					dp[i + 1][j + 1][k + (a[j + 1] == b[k + 1])] = dp[i][j][k] + (a[j + 1] == c[dp[i][j][k] + 1]);
					trace1[i + 1][j + 1][k + (a[j + 1] == b[k + 1])] = 1;
					trace2[i + 1][j + 1][k + (a[j + 1] == b[k + 1])] = (a[j + 1] == b[k + 1]);

				}
				if (dp[i + 1][j + (a[j + 1] == b[k + 1])][k + 1] > dp[i][j][k] + (b[k + 1] == c[dp[i][j][k] + 1])) {
					dp[i + 1][j + (a[j + 1] == b[k + 1])][k + 1] = dp[i][j][k] + (b[k + 1] == c[dp[i][j][k] + 1]);
					trace2[i + 1][j + (a[j + 1] == b[k + 1])][k + 1] = 1;
					trace1[i + 1][j + (a[j + 1] == b[k + 1])][k + 1] = (a[j + 1] == b[k + 1]);
				}
			}
	int len = -1;
	for (int i = 0; i <= lena + lenb; i++) {
		if (dp[i][lena][lenb] < lenc) {
			len = i;
			break;
		}
	}
	if (len == -1) {
		cout << "TRETRAU" << '\n';
		return 0;
	}
	cout << len << '\n';
	string res = "";
	int cura = lena, curb = lenb;
	while (len) {
		if (trace1[len][cura][curb] == 1) res += a[cura];
		else res += b[curb];
		int tmp = cura;
		if (trace1[len][cura][curb]) cura --;
		if (trace2[len][tmp][curb]) curb --;
		len --;
	}
	reverse(res.begin(), res.end());
	cout << res;
}
