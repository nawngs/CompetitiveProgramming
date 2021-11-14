#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

string s;

bool check(string s) {
	string s_rev = s;
	reverse(s_rev.begin(), s_rev.end());
	return (s == s_rev);
}

void sol() {
	cin >> s;
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		string tam = "";
		for (int j = i; j < s.size(); j++) {
			tam += s[j];
			if (check(tam)) ans++;
		}
	}
	cout << ans << '\n';
	return ;
}

int main() {
	slow;
	int t;
	cin >> t;
	while (t --) sol();	
}
