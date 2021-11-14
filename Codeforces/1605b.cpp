#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

string s;

vector < int > res;

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	int dem = 0;
	for (int i = 1; i <= n; i++) if (s[i] == '1') dem ++;
	res.clear();
	for (int i = n; i >=  n - dem + 1; i --) if (s[i] == '0') res.push_back(i);
	for (int i = n - dem; i >= 1; i--) if (s[i] == '1') res.push_back(i);
	reverse(res.begin(), res.end());
	if (res.size() == 0) cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		cout << res.size() << ' ';
		for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
		cout << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
