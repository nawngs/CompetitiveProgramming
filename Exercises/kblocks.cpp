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
	const ll nmax = 2e5;
	const ll MOD = 1e9 + 7;
	const ll base = 2309;

	void fre() {
		string finp = NAME + ".inp";
		string fout = NAME + ".out";
		freopen(finp.c_str(), "r", stdin);
		freopen(fout.c_str(), "w", stdout);
	}

	int n, k, a[100003], dp[100003][103];

	int main() {
		fast;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(dp, 64, sizeof(dp));
		dp[1][1] = a[1];
		for (int i = 2; i <= n; i++) 
			dp[i][1] = max(dp[i - 1][1], a[i]);
		for (int j = 2; j <= k; j++) {
			stack < pii > st;
			for (int i = 1; i <= n; i++) {
				int val = dp[i - 1][j - 1], l;
				while (st.size() && a[i] >= a[st.top().se]) {
					val = min(val, st.top().fi);
					st.pop();
				}
				if (st.size()) l = st.top().se;
				else l = 0;
				st.push({val, i});
				dp[i][j] = min(dp[l][j], val + a[i]);
			}
		}
		cout << dp[n][k];
	}
