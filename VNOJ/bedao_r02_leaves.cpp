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

int n, cnt[100005], f[100005];

void sol() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	memset(f, 0, sizeof(f));
	int end = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		end = max(end, x);
		cnt[x] ++;
	}
	f[0] = 1;
	for (int i = 1; i <= end; i++) {
		if(cnt[i] > f[i - 1] * 2) {
			cout << "NO" << '\n';
			return;
		} 
		f[i] = f[i - 1] * 2 - cnt[i];
		if (f[i] == 0) {
			if (i == end) cout << "YES" << '\n';
			else cout << "NO" << '\n';
			return ;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	slow;
	int t;
	cin >> t;
	while (t --) sol();	
}
