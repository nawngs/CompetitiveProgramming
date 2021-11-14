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

string n;

void sol() {
	cin >> n;
	int ans = 1e9;
	for (int i = 0; i < n.size(); i++) {
		for (int j = i + 1; j < n.size(); j++) {
			if (n[j] != '0' && n[j] != '5') continue;
			if (n[j] == '5' && (n[i] == '2' || n[i] == '7')) {
				ans = min(ans, j - i - 1 + (int) n.size() - j - 1);
			}
			if (n[j] == '0' && (n[i] == '0' || n[i] == '5')) {
				ans = min(ans, j - i - 1 + (int) n.size() - j - 1);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
 