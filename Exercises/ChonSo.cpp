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

const string NAME = "ChonSo";
const ll ESP = 1e-9;
const ll INF = 1e18;
const int nmax = 1e6 + 2;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, cnt[1000005];

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x] ++;
	}
	sort(cnt, cnt + nmax, greater < int >());
	cout << cnt[0] + cnt[1] << '\n';
}
