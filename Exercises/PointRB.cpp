#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "pointRB";
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

int n, m;

vector < int > r, b;
ll pos_r[100003], pos_b[100003], pos[200003], sum[200003], pre[200003], suff[200003];

vector < pll > c;

ll dp[200003];

//1 = r
//2 = b

void minimize(ll &x, ll y) {
	x = min(x, y);
}

void create_pos() {
	int cnt_r = 0;
    memset(pos, 255, sizeof(pos));
    memset(pos_r, 255, sizeof(pos_r));
    memset(pos_b, 255, sizeof(pos_b));
	pos_r[0] = pos_b[0] = 0;
	for (int i = 1; i < (int) c.size(); i++) {
		cnt_r += (c[i].se == 1);
		cnt_r -= (c[i].se == 2);
		if (cnt_r >= 0) pos[i] = pos_r[cnt_r];
		if (cnt_r <= 0) pos[i] = pos_b[abs(cnt_r)];
		if (cnt_r >= 0) pos_r[cnt_r] = i;
		if (cnt_r <= 0) pos_b[abs(cnt_r)] = i;
	}
}

void create_pre_suff() {
    memset(pre, 255, sizeof(pre));
    memset(suff, 255, sizeof(suff));
	int pos_c[3];
	pos_c[1] = pos_c[2] = -1;
	for (int i = 1; i < (int) c.size(); i++) {
		if (c[i].se == 1 && pos_c[2] != -1) pre[i] = pos_c[2];
		if (c[i].se == 2 && pos_c[1] != -1) pre[i] = pos_c[1];
		pos_c[c[i].se] = i;
	}
	pos_c[1] = pos_c[2] = -1;
	for (int i = (int) c.size() - 1; i > 0; i--) {
		if (c[i].se == 1 && pos_c[2] != -1) suff[i] = pos_c[2];
		if (c[i].se == 2 && pos_c[1] != -1) suff[i] = pos_c[1];
		pos_c[c[i].se] = i;

	}
}

void create_sum() {
    memset(sum, 255, sizeof(sum));
	sum[0] = 0;
	for (int i = 1; i < (int) c.size(); i++) {
		sum[i] = sum[i - 1] + c[i].fi;
	}
}

ll calc(ll l, ll r) {
	return (sum[r] - sum[l - 1]) - 2 * (sum[(l + r) / 2] - sum[l - 1]);
}

ll min_total_length(vector < int > r, vector < int > b) {
	c.push_back({-1, -1});
	for (int i = 0; i < (int)r.size(); i++) c.push_back({r[i], 1});
	for (int i = 0; i < (int)b.size(); i++) c.push_back({b[i], 2});
	sort(c.begin(), c.end());	
	create_pos();
	create_pre_suff();
	create_sum();
	for (int i = 1; i <= c.size(); i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 1; i < (int) c.size(); i++) {
		if (pre[i] != -1) minimize(dp[i], dp[i - 1] + c[i].fi - c[pre[i]].fi);
		if (suff[i] != -1) minimize(dp[i], dp[i - 1] + c[suff[i]].fi - c[i].fi);
		if (pos[i] != -1) minimize(dp[i], dp[pos[i]] + calc(pos[i] + 1, i));
	}
	return dp[(int) c.size() - 1];

}

int main() {
	fast;
	fre();
	cin >> n >> m;
	r.resize(n);
	b.resize(m);
	for (auto &x : r) cin >> x;
	for (auto &x : b) cin >> x;
	cout << min_total_length(r, b);
}

