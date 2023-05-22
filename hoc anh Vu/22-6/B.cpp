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
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[8], dp[300000][(1 << 8)], f[(1 << 8)];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	int ans = 0, pos1 = 0, pos2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[j];
		for (int bit = 0; bit < (1 << m); bit++) {
			dp[i][bit] = 1e9 + 7;
			for (int j = 0; j < m; j++) if (getbit(bit, j)) dp[i][bit] = min(dp[i][bit], a[j]);
			//cout << i << " " << bit << " " << dp[i][bit] << '\n';
			if (ans < min(dp[i][bit], dp[f[(1 << m) - 1 - bit]][(1 << m) - 1 - bit])) {
				ans = min(dp[i][bit], dp[f[(1 << m) - 1 - bit]][(1 << m) - 1 - bit]);
				pos1 = f[(1 << m) - 1 - bit];
				pos2 = i;
			}
		}
		for (int bit = 0; bit < (1 << m); bit ++) if (dp[i][bit] >= dp[f[bit]][bit]) f[bit] = i;
		
	}
	cout << pos1 + 1 << " " << pos2 + 1 << '\n';
}
