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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200005], dp[200005], cnt[200005];

void sol() {
	cin >> n;
	for (int i = 0; i <= n + 1; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	a[n + 1] = 1e9;
	sort(a + 1, a + n + 1);
	int pos = 1;
	stack < int > st;
	for (int i = 0; i <= n; i++) {
		while (a[pos] <= i && pos <= n) pos ++;
		if (cnt[i] >= 2) st.push(i);
		//cout << pos << '\n';
		if (pos - cnt[i] - 1 < i) dp[i] = -1;
		else {
			if (i == 0) dp[i] = cnt[i];
			else {
				if (dp[i - 1] == -1) dp[i] = -1;
				else {
					if (cnt[i - 1] != 0) dp[i] = dp[i - 1] - cnt[i - 1] + cnt[i];
					else {
						while (st.size() && cnt[st.top()] < 2) st.pop();
						if (!st.size()) dp[i] = -1;
						else {
							cnt[st.top()] --;
							dp[i] = dp[i - 1] + i - 1 - st.top() + cnt[i];
						}
					} 
				}
			}
		}
		cout << dp[i] << ' ';
	}
	cout << '\n';
}

int main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
