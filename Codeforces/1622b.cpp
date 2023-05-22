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

int n, a[200005], res[200005];

string s;

vector < pii > b, c;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	b.clear();
	c.clear();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') b.push_back({a[i + 1], i + 1});
		if (s[i] == '1') c.push_back({a[i + 1], i + 1});
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i = 0; i < b.size(); i++) res[b[i].se] = i + 1;
	for (int i = 0; i < c.size(); i++) res[c[i].se] = i + b.size() + 1;
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';	
	cout << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
