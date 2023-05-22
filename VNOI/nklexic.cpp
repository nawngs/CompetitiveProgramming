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
const ll INF = 4e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

bool used[30];

ll f[30][30], gt[30];


void create() {
	f[0][0] = 1;
	for (int j = 1; j <= 26; j++) {
		f[0][j] = 1;
		for (int i = 1; i <= 26; i++) {
			f[i][j] = f[i - 1][j - 1] * j;
			if (f[i][j] > INF) f[i][j] = INF;
		}
	}
}

bool checkdata_str(string s) {
	if (s.size() != m) return false;
	memset(used, false, sizeof(used));
	for (int i = 0; i < m; i++) {
		if (s[i] - 'a' + 1 > n) return false;
		if (s[i] < 'a') return false;
		if (used[s[i] - 'a'] == 1) return false;
		used[s[i] - 'a'] = 1;
	}
	return true;
}

bool checkdata_num(ll x) {
	if (x > f[m][n] || x <= 0) return false;
	return true;
}

void solve1(string s) {
	ll ans = 0;
	memset(used, false, sizeof(used));
	for (int i = 0; i < m; i++) {
		ll dem = 0;
		for (int j = 0; j < s[i] - 'a'; j++) dem += !used[j];
		ans += dem * f[m - i - 1][n - i - 1];
		used[s[i] - 'a'] = true;
	}
	cout << ans + 1 << '\n';
}

void solve2(ll s) {
	string ans = "";
	memset(used, false, sizeof(used));
	for (int i = 1; i <= m; i++) {
		ll dem = 0;
		ll pre = 0;
		for (int j = 0; j < n; j++) {
			if (!used[j]) {
				dem ++;
				pre = j;
				if (dem *  f[m - i][n - i] >= s) break;
			}
		}
		char c = 'a' + pre;
		ans += c;
		s -= (dem - 1) * f[m - i][n - i];
		used[pre] = 1;
	}
	cout << ans << '\n';
}

void sol() {
	cin >> n >> m;
	char query;
	cin >> query;
	if (query == 'P') {
		string s;
		cin >> s;
		if (!checkdata_str(s)) {
			cout << "Incorrect data" << '\n';
			return ;
		}
		else solve1(s);
	}
	else {
		ll tt;
		cin >> tt;
		if (!checkdata_num(tt)) {
			cout << "Incorrect data" << '\n';
			return ;
		}
		else solve2(tt);
	}
}

int main() {
	create();
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
