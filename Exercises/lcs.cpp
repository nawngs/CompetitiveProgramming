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

const string NAME = "LCS";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[1003], b[1000003], dp[1003][1003], val[2000003];

vector < int > adj[2000003];

void roi_rac() {
	vector < pii > temp;
	for (int i = 1; i <= n; i++) temp.push_back({a[i], i});
	for (int i = 1; i <= m; i++) temp.push_back({b[i], i + n});
	sort(temp.begin(), temp.end());
	int dem = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (i != 0) dem += (temp[i].fi != temp[i - 1].fi);
		if (temp[i].se <= n) {
			val[dem] = a[temp[i].se];
			a[temp[i].se] = dem;
		}
		else {
			val[dem] = b[temp[i].se - n];
			b[temp[i].se - n] = dem;
		}
	} 
}

int bs(int pos, int val) {
	int l = 0, r = adj[pos].size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (adj[pos][mid] > val) {
			ans = adj[pos][mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	roi_rac();
	for (int i = 1; i <= m; i++) adj[b[i]].push_back(i);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) dp[i][j] = INF;
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] != INF) {
				if (dp[i + 1][j] > dp[i][j]) dp[i + 1][j] = dp[i][j];
				
				int tam = bs(a[i + 1], dp[i][j]);
				if (tam == -1) continue;
				if (dp[i + 1][j + 1] > tam) dp[i + 1][j + 1] = tam;
				ans = max(ans, j + 1);
			}
		}
	}
	cout << ans << '\n';
	vector < int > res;
	res.clear();
	int pos = n;
	while (ans) {
		if (dp[pos][ans] == dp[pos - 1][ans]) pos --;
		else {
			res.push_back(pos);
			ans --;
		}
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << val[a[x]] << " ";
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
