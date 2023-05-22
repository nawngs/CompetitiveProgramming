#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const string NAME = "ANAGRAM";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const int base = 2309;
const int MOD = 1e9 + 7;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int pow_base[27];

vector < int > adjs[4002], adjt[4002];

string s, t;

bool bs(int val, int pos) {
	int l = 0, r = adjs[pos].size() - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (adjs[pos][mid] == val) return true;
		if (adjs[pos][mid] > val) r = mid - 1;
		if (adjs[pos][mid] < val) l = mid + 1;
	}
	return false;
}

void sol() {
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	ll temp = 1;
	for (int i = 0; i <= 26; i++) {
		temp %= MOD;
		//cout << temp << '\n';
		pow_base[i] = temp;
		temp *= base;
	}
	for (int i = 1; i <= n; i++) {
		ll tam = 0;
		for (int j = i; j <= n; j++) {
			tam += pow_base[26 - (s[j] - 'a')];
			tam %= MOD;
			adjs[j - i + 1].push_back(tam);
		}
	}
	for (int i = 1; i <= m; i++) {
		ll tam = 0;
		for (int j = i; j <= m; j++) {
			tam += pow_base[26 - (t[j] - 'a')];
			tam %= MOD;
			adjt[j - i + 1].push_back(tam);
		}
	}
	for (int i = min(n, m); i >= 1; i--) {
		sort(adjs[i].begin(), adjs[i].end());
		for (auto val : adjt[i]) {
			if (bs(val, i)) {
				cout << i << '\n';
				return ;
			}
		}
	}
	cout << 0;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}


