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

const string NAME = "ghepso";
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

ll m, k, a[15], cnt[15];

string val[15];

vector < string > res;

bool check(string s) {
	int val = 0;
	for (int i = 0; i < s.size(); i++) val = val * 10 + s[i] - '0';
	return (val % m == 0);
} 

void sol() {
	cin >> k >> m;
	memset(cnt, 255, sizeof(cnt));
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		val[a[i]] = '0' + a[i];
	}
	while (1) {
		ll tam, gt = INF;
		for (int i = 0; i <= 9; i++) {
			if (val[i].size() == 0) continue;
			if (gt > val[i].size()) {
				gt = val[i].size();
				tam = i;
			}
		}
		if (tam == 0 && gt == 9) break;
		if (tam != 0 && gt == 8) break;
		if (check(val[tam])) {
			cout << val[tam] << '\n';
			return ;
		}
		res.push_back(val[tam]);
		char c = '0' + tam;
		val[tam] = c + res[++ cnt[tam]];
		
	}
	cout << -1;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
