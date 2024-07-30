#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define plli pair < pll, int >
#define fi first
#define se second

using namespace std;

const int NMAX = 1E5;

int n, k, a[NMAX + 3];

ll s[NMAX + 3];

ll dp[NMAX + 3][2];

int trace[NMAX + 3][203];

long double slope(int i, int j, int k) {
	return (long double) (dp[i][k] - dp[j][k]) / (s[i] - s[j]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= k; i++) {
		deque < int > dq;
		dq.push_front(i - 1);
		for (int j = i; j <= n; j++) {
			while (dq.size() > 1 && slope(dq[dq.size() - 2], dq.back(), (i & 1) ^ 1) >= (s[n] - s[j])) dq.pop_back();
			int v = dq.back();
			pll temp = {-s[v] * (s[n] - s[j]) + dp[v][(i & 1) ^ 1], v};
			temp.fi += s[j] * (s[n] - s[j]);
			dp[j][i & 1] = temp.fi; trace[j][i] = temp.se;
			// cout << j << " " << i << " " << dp[j][i & 1] << '\n';
			while (dq.size() && s[dq.front()] == s[j]) dq.pop_front();
			while (dq.size() > 1 && slope(dq[0], dq[1], (i & 1) ^ 1) <= slope(dq[0], j, (i & 1) ^ 1)) dq.pop_front();
			dq.push_front(j);
		}
	}
	int pos = -1;
	for (int i = 1; i <= n; i++) if (pos == -1 || dp[i][k & 1] > dp[pos][k & 1]) pos = i;
	cout << dp[pos][k & 1] << '\n';
	for (int i = k; i >= 1; i--) {
		cout << pos << " ";
		pos = trace[pos][i];
	}
}