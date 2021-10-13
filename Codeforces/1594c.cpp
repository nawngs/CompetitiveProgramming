#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n;

string s;
char c;

bool check[300005];

void sol() {
	cin >> n >> c >> s;
	memset(check, true, sizeof(check));
	bool th = true;
	int maxpos = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != c) {
			check[i + 1] = false;
			th = false;
		}
		else maxpos = i + 1;
	}
	if (th) {
		cout << 0 << '\n';
		return;
	}
	if (maxpos > n / 2) {
		cout << 1 << '\n' << maxpos << '\n';
		return ;
	}
	cout << 2 << '\n' << n - 1 << " " << n << '\n';
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
