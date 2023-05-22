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

int n, m, sum[(1 << 20)], cnt[20][(1 << 20)], dp[(1 << 20)];

string s;

int main() {
	fast;
	cin >> n >> m >> s;
	for (int i = 1; i < n; i++) {
		//cout << s[i] << " " << s[i] - 'a' << " " << s[i - 1] - 'a' << '\n';
		cnt[s[i] - 'a'][(1 << (s[i - 1] - 'a'))] ++;
		cnt[s[i - 1] - 'a'][(1 << (s[i] - 'a'))] ++;
	}
	for (int i = 0; i < m; i++) {
		for (int bit = 1; bit < (1 << m); bit++) 
			for (int j = 0; j < m; j++) {
				if (bit & (1 << j)) {
					cnt[i][bit] = cnt[i][bit - (1 << j)] + cnt[i][(1 << j)];
					//cout << i << " " << bit << " " << cnt[i][bit] << '\n';
					break;
				}
			}
	}
	for (int bit = 0; bit < (1 << m); bit++) {
		for (int i = 0; i < m; i++) {
			if (bit & (1 << i)) {
				sum[bit] += cnt[i][(1 << m) - 1 - bit];
			}
		}
		//cout << bit << " " << sum[bit] << '\n';
	}
	for (int i = 1; i < (1 << m); i++) dp[i] = INF;
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) dp[i] = min(dp[i], dp[i ^ (1 << j)] + sum[i]);
			
		}
	}
	cout << dp[(1 << m) - 1];
}
