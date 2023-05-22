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

string s;

ll cnt[500005], k;

void sol() {
	cin >> s;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int n, x, y;
		cin >> n >> x >> y;
		x --;
		y --;
		cnt[x] += n;
		cnt[y + 1] -= n;
	}
	ll tam = s[0] - 'A';
	tam += cnt[0];
	tam %= 26	;
	char c = 'A' + tam;
	cout << c;
	for (int i = 1; i < s.size(); i++) {
		cnt[i] += cnt[i - 1];
		tam = s[i] - 'A';
		tam += cnt[i];
		tam %= 26;
		c = 'A' + tam;
		cout << c;
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
