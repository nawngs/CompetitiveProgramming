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

int a, b, c;

void sol() {
	cin >> a >> b >> c;
	cout << max(0, max(b, c) + 1 - a) << " " << max(0, max(a, c) + 1 - b) << " " << max(0, max(a, b) + 1 - c) << '\n';
}

int main() {
	fastflow;
	int t = 1;
	cin >> t;
	while (t --) sol();
}
