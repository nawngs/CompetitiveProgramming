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

ll m, cnt[10];

void sol() {
	cin >> m;
	if (m < 10) {
		cout << 10 + m << '\n';
		return;
	}
	int i = 9;
	while (m > 1 && i >= 2) {
		if (m % i == 0) {
			cnt[i] ++;
			m /= i;
		}
		else i --;
	}
	if (m != 1) {
		cout << -1 << '\n';
		return ;
	}
	for (int i = 1; i <= 9; i++) while (cnt[i] --) cout << i;

}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
