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
string s1, s2;

void sol() {
	cin >> n;
	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	for (int i = 1; i <= n; i++) {
		if (s1[i] == s2[i] && s1[i] == '1') {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
 }

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
