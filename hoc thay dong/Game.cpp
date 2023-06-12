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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, F, A, B, M, b[nmax + 3], dp[nmax + 3], dq[nmax + 3], l = 0, r = -1;

int main() {
	fast;
	//fre();
	cin >> n >> k >> F >> A >> B >> M;
	b[1] = F;
	for (int i = 2; i <= n; i++) 
		b[i] = (b[i - 1] * A + B) % M;
	dp[0] = 0;
	dq[++ r] = 0;
	for (int i = 1; i <= n + 1; i++) {
		while (dq[l] < i - k) 
			l ++;
		dp[i] = dp[dq[l]] + b[i];
		while (dp[dq[r]] > dp[i]) 
			r--;
		dq[++ r] = i;
	}
	cout << dp[n + 1];
}
