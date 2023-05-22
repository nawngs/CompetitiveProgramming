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

int len;

void solve(int pos) {
	int l = pos + 1, r = len, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		cout << 2 << " " << pos << " " << mid << '\n';
		int tam1;
		cin >> tam1;
		cout << 2 << " " << pos + 1 << " " << mid - 1 << '\n';
	}
}

int main() {
	fast;
	cin >> len;
	vector < char > res;
	res.resize(len + 1, '#');
	for (int i = 1; i <= len; i++) {
		if (res[i] == '#') {
			cout << 1 << " " << i << '\n';
			cin >> res[i];
		}
		solve(i);
	}
}
