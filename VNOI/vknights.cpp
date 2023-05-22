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

int n;

pll dp[103][(1 << 3)][(1 << 3)];

bool a[3][103];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

int countbits(int x){
	int dem = 0;
	for(int i = 0; i < 3; i++){
		if(getbit(x, i)) dem ++;
	}
	return dem;
}

bool check(int pos, int bit1, int bit2) {
	if (pos - 1 >= 0 && getbit(bit1, pos - 1)) return false;
	if (pos + 1 < 3 && getbit(bit1, pos + 1)) return false;
	if (pos + 2 < 3 && getbit(bit2, pos + 2)) return false;
	if (pos - 2 >= 0 && getbit(bit2, pos - 2)) return false;
	return true;
}

void getmax(pll &x, pll y, ll val) {
	if (x.fi < y.fi + val) x = {y.fi + val, y.se};
	else if (x.fi == y.fi + val) x.se += y.se;
} 

void readINP() {
	cin >> n;
	memset(a, 1, sizeof(a));
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x --;
		if (x != -1) a[x][i] = false;
	}
}

void init() {
	for (int i = 0; i <= n; i++)
		for (int bit1 = 0; bit1 < (1 << 3); bit1++)
			for (int bit2 = 0; bit2 < (1 << 3); bit2++) dp[i][bit1][bit2] = {-1, -1};
	dp[0][0][0] = {0, 1};
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int bit1 = 0; bit1 < (1 << 3); bit1++) {
			for (int bit2 = 0; bit2 < (1 << 3); bit2++) {
				if (dp[i - 1][bit1][bit2].fi == -1) continue;
				for (int bit = 0; bit < (1 << 3); bit++) {
					bool th = 1;
					for (int k = 0; k < 3; k++) {
						if (!getbit(bit, k)) continue;
						if (!a[k][i]) {
							th = false;
							break;
						}
						if (!check(k, bit1, bit2)) {
							th = false;
							break;
						}
					}
					if (!th) continue;
					getmax(dp[i][bit2][bit], dp[i - 1][bit1][bit2], countbits(bit));
					//cout << i << " " << bit1 << " "  << bit2 << " " << bit << " " << dp[i][bit2][bit].fi << '\n';
				}
			}
		}
	}
}

void printANS() {
	pll res = {0, 1};
	for (int i = 1; i <= n; i++) 
		for (int bit1 = 0; bit1 < (1 << 3); bit1++)
			for (int bit2 = 0; bit2 < (1 << 3); bit2++) getmax(res, dp[i][bit1][bit2], 0);
	cout << res.fi << " " << res.se << '\n';

}

int main() {
	fast;
	//fre();
	readINP();
	init();
	solve();
	printANS();
}
