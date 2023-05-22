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

const string NAME = "ddd";
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

int m, n, a[53], b[53], cntb[53], res[53][53], cnt[53];

bool check(int row) {
	if (row == m + 1) {
		bool th = true;
		for (int i = 1; i <= m; i++) {
			if (cntb[i] != 0) {
				th = false;
				break;
			}
		}
		return th;
	}
	int tam = a[row];
	int temp = 0;
	for (int i = m; i >= 1; i--) {
		if (tam == 0) {
			cntb[i] += temp;
			break;
		}
		if (cntb[i] == 0) {
			cntb[i] += temp;
			temp = 0;
			continue;
		}
		int pre = temp;
		if (tam > cntb[i]) {
			temp = cntb[i];
			tam -= cntb[i];
			cntb[i] = 0;
		}
		else {
			temp = tam;
			cntb[i] -= tam;
			tam = 0;
		}
		cntb[i] += pre;
	}
	//cout << row << " " << tam << '\n';
	if (tam != 0) return false;
	else return check(row + 1);
}

void create(int i_id, int j_id) {
	//cout << i_id << " " << j_id << '\n';
	if (i_id == m + 1) return ;
	bool th;
	for (int i = 1; i <= m; i++) cntb[i] = cnt[i];
	if (j_id == n) th = check(i_id + 1);
	else {
		vector < int > tam;
		for (int i = j_id + 1; i <= n; i++) tam.push_back(i);
		sort(tam.begin(), tam.end(), [&](int &x, int &y) {
			return b[x] > b[y];
		});

		int val = a[i_id];
		if (val != 0) {
			for (auto x : tam) {
				val --;
				cntb[b[x]] --;
				cntb[b[x] - 1] ++;
				if (val == 0) break;
			}
		}
		if (val != 0) th = false;
		else th = check(i_id + 1);
	}
	if (!th) {
		res[i_id][j_id] = 1;
		a[i_id] --;
		cnt[b[j_id]] --;
		b[j_id] --;
		cnt[b[j_id]] ++;
	}
	if (a[i_id] == 0) create(i_id + 1, 1);
	else create(i_id, j_id + 1);
}

void sol() {
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		cntb[i] = 0;
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) {
		if (a[i] > n) {
			cout << -1 << '\n';
			return ;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > m) {
			cout << -1 << '\n';
			return ;
		}
		cnt[b[i]] ++;
		cntb[b[i]] ++;
	}
	if (!check(1)) {
		cout << -1 << '\n';
		return ;
	}
	for (int i = 1; i <= m; i++) cntb[i] = cnt[i];
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++) res[i][j] = 0; 
	create(1, 1);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) cout << res[i][j];
	cout << '\n';
}

int main() {
	fast;
	//fre();
	while (cin >> m >> n && m != 0 && n != 0) sol();
}
/*
5 5
3 1 3 4 0
3 0 4 1 3
*/