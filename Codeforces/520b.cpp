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

int a, b, dp[20003];

void sol() {
	cin >> a >> b;
	dp[a] = 1;
	queue < int > que;
	que.push(a);
	while (que.size()) {
		auto u = que.front();
		que.pop();
		if (u == b) {
			cout << dp[u] - 1;
			return ;
		}
		if (u < b) {
			if (dp[u * 2] == 0) {
				dp[u * 2] = dp[u] + 1;
				que.push(u * 2);
			}
		}
		if (u > 1 && dp[u - 1] == 0) {
			dp[u - 1] = dp[u] + 1;
			que.push(u - 1);
		} 
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
