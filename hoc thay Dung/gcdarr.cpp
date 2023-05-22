#include <bits/stdc++.h>

#define name "gcdarr"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[103], cnt[103];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			cout << "NO" << '\n';
			return ;
		}
	}
	bool th = 1;
	for (int i = 2; i <= 50; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; j++) 
			cnt[a[j] % i] ++;
		th = false;
		for (int j = 0; j < i; j++) 
			if (cnt[j] < 2) th = 1;
		if (!th) {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}