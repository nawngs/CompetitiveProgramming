#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "delta";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, t, k, a[500003], st1[500003][20], st2[500003][20], mu[500003];

int getmax(int l, int r) {
	int k = log2(r - l + 1);
	return max(st1[l][k], st1[r - (1 << k) + 1][k]);
}

int getmin(int l, int r) {
	int k = log2(r - l + 1);
	return min(st2[l][k], st2[r - (1 << k) + 1][k]);
}

void sol() {
	cin >> t >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st1[i][0] = st2[i][0] = a[i];
	}
	for (int j = 1; 1 << j <= n; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
		}
	ll res1 = 0;
	int l = 1;
	for (int i = 1; i <= n; i++) {
		while (getmax(l, i) - getmin(l, i) > k) l ++;
		res1 = (res1 + i - l + 1) % MOD;
	}
	cout << res1 << " ";
	sort(a + 1, a + n + 1);
	res1 = 0;
	l = 1;
	mu[0] = 1;
	for (int i = 1; i <= n; i++) mu[i] = (mu[i - 1] * 2) % MOD;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[l] > k) l ++;
		//cout << i << " " << ans << '\n';
		res1 = (res1 + mu[i - l]) % MOD;
	}
	cout << res1;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
