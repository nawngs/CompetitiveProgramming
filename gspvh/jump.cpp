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
const int INF = 2e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int r, c, k, a[1000][4], dp[1000][2002][16], calc[1000][16], cnt[16];

bool check[16][16];

vector < int > valid;

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

int countbits(int x){
	int dem = 0;
	for(int i = 0; i < c; i++){
		if(getbit(x, i)) dem ++;
	}
	return dem;
}

void sol() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)	
		for (int j = 0; j < c; j++) cin >> a[i][j];

	for (int i = 0; i < (1 << c); i++) {
		bool th = 1;
		for (int j = 1; j < c; j++) {
			if (getbit(i, j) && getbit(i, j - 1)) {
				th = false;
				break;
			}
		}
		if (th) valid.push_back(i);
	}
	memset(check, 1, sizeof(check));
	for (auto x : valid) {
		for (auto y : valid) {
			for (int i = 0; i < c; i++) 
				if (getbit(x, i) && getbit(y, i)) {
					check[x][y] = false;
					break;
				}
		}
	}
	for (int i = 0; i < r; i++) for (auto bit : valid) for (int j = 0; j < c; j++) calc[i][bit] += (a[i][j] * getbit(bit, j));
	for (auto bit : valid) cnt[bit] = countbits(bit);
	for (int i = 0; i < r; i++)
		for (int j = 0; j <= k; j++)
			for (int bit = 0; bit < (1 << c); bit++) dp[i][j][bit] = -INF; 
	for (auto bit : valid) dp[0][cnt[bit]][bit] = calc[0][bit];
	for (int i = 1; i < r; i++) {
		for (int j = 0; j <= k; j++) {
			for (auto bit : valid) {
				if (cnt[bit] > j) continue;
				for (auto prebit : valid) if (check[bit][prebit]) dp[i][j][bit] = max(dp[i][j][bit], dp[i - 1][j - cnt[bit]][prebit] + calc[i][bit]);
			}
		}
	}
	int res = -INF;
	for (int i = 0; i < r; i++) 
		for (auto bit : valid) res = max(res, dp[i][k][bit]);
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
