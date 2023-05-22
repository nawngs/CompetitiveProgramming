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

string x, y, z;

ll dp[1000003][2][2];

void cong(ll &x, ll y) {
	(x + y) % MOD;
}

ll calc(ll l, ll r) {
	return (l + r) * (r - l + 1) / 2;
}

void sol() {
	cin >> x >> y >> z;
	x = ' ' + x;
	y = ' ' + y;
	z = ' ' + z;
	int len = max(x.size(), max(y.size(), z.size()));
	while (x.size() < len) x += '~';
	while (y.size() < len) y += '~';
	while( z.size() < len) z += '~';
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i < len; i++) {
		for (int stt1 = 0; stt1 <= 1; stt1++) {
			if (stt1 == 0 && x[i] != '?' && y[i] != '?' && x[i] != y[i]) continue;
			for (int stt2 = 0; stt2 <= 1; stt2++) {
				if (stt2 == 0 && y[i] != '?' && z[i] != '?' && y[i] != z[i]) continue;
				for (int stt1pr = 0; stt1pr <= stt1; stt1pr++) {
					for (int stt2pr = 0; stt2pr <= stt2; stt2pr++) {
						ll lx, rx, ly, ry, lz, rz;
						lx = rx = ly = ry = lz = rz = -1;
						if (x[i] != '?') lx = rx = x[i] - 'a';
						if (y[i] != '?') ly = ry = y[i] - 'a';
						if (z[i] != '?') lz = rz = z[i] - 'a';
						if (stt1pr < stt1 && y[i] != '?' && x[i] != '?' && y[i] >= x[i]) continue;
						if (stt2pr < stt2 && z[i] != '?' && y[i] != '?' && z[i] >= y[i]) continue;
						if (lx == -1) {
							if (ly == -1) {
								if (stt1 == )
							}
						}

					}
				}
			}
		}
		/*
		if (x[i] == '?' && y[i] == '?' && z[i] == '?') {
			cong(dp[i][0][0], dp[i - 1][0][0] * 26);
			cong(dp[i][1][0], dp[i][1][0] * 26 * 26 + dp[i][0][0] * calc(1, 25));
			cong(dp[i][0][1], dp[i][0][1] * 26 * 26 + dp[i][0][0] * calc(1, 25));
			cong(dp[i][1][1], dp[i][0][0])
		}	
		*/
	}
} 

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
 /*
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

string x, y, z;

ll dp[1000003][2][2];

void cong(ll &x, ll y) {
	(x + y) % MOD;
}

ll calc(ll l, ll r) {
	return (l + r) * (r - l + 1) / 2;
}

void sol() {
	cin >> x >> y >> z;
	x = ' ' + x;
	y = ' ' + y;
	z = ' ' + z;
	int len = max(x.size(), max(y.size(), z.size()));
	while (x.size() < len) x += '~';
	while (y.size() < len) y += '~';
	while( z.size() < len) z += '~';
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i < len; i++) {
		if (x[i] == '?' && y[i] == '?' && z[i] == '?') {
			cong(dp[i][0][0], dp[i - 1][0][0] * 26);
			cong(dp[i][1][0], dp[i - 1][1][0] * 26 * 26 + dp[i - 1][0][0] * calc(1, 25));
			cong(dp[i][0][1], dp[i - 1][0][1] * 26 * 26 + dp[i - 1][0][0] * calc(1, 25));
			cong(dp[i][1][1], dp[i - 1][0][0] * (26 * 25 * 4) + dp[i - 1][1][0] * 25 * 13 + dp[i - 1][0][1] * 25 * 13 + dp[i - 1][1][1] * 26 * 26 * 26);
			continue;
		}	
		if (y[i] == '?' && z[i] == '?') {
			cong(dp[i][0][0], dp[i - 1][0][0]);
			cong(dp[i][1][0], dp[i - 1][1][0] * 26 + dp[i - 1][0][0] * x[i] - 'a' + 1);
			cong(dp[i][0][1], dp[i - 1][0][1] * x[i] - 'a' + 1 + dp[i - 1][0][0] * 13 * 25);
			cong(dp[i][1][1], dp[i - 1][0][0] * ())

		}
	}
} 

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
 */