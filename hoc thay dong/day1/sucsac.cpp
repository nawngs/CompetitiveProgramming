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

int ss[4][6], total = 0, ans = 0;

// 0 la gia tri mat ben tren
// 1 la gia tri mat ben phai
// 2 la gia tri mat truoc 
// 3 la gia tri mat sau
// 4 la gia tri mat ben trai
// 5 la gia tri mat duoi

int tt[24][2];

// tt[i][0] = index cua mat ben phai cua trang thai i
// tt[i][1] = index cua mat tren cua trang thai i

void readINP() {
	for (int i = 0; i < 4; i++) {
		cin >> ss[i][0] >> ss[i][5] >> ss[i][1] >> ss[i][4] >> ss[i][2] >> ss[i][3];
		for (int j = 0; j < 6; j++) total += ss[i][j];
	}
}

void init_all_tt() {
	int dem = 0;
	for (int j = 0; j < 6; j++) 
		for (int k = 0; k < 6; k++) 
			if (j != k && j + k != 5) {
				tt[dem][0] = j;
				tt[dem][1] = k;
				dem ++;
			}
}

int find_right(int i) {
	return tt[i][0];
}

int find_left(int i) {
	return 5 - find_right(i);
}

int find_above(int i) {
	return tt[i][1];
}

int find_below(int i) {
	return 5 - find_above(i);
}

void solve(int a, int b, int c, int d) {
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 24; j++) {
			for (int p = 0; p < 24; p++) {
				for (int q = 0; q < 24; q++) {
					int sum = 0;
					if (ss[a][find_right(i)] != ss[b][find_left(j)]) continue;
					sum += 2 * ss[a][find_right(i)];
					if (ss[a][find_below(i)] != ss[c][find_above(p)]) continue;
					sum += 2 * ss[a][find_below(i)];
					if (ss[b][find_below(j)] != ss[d][find_above(q)]) continue;
					sum += 2 * ss[b][find_below(j)];
					if (ss[c][find_right(p)] != ss[d][find_left(q)]) continue;
					sum += 2 * ss[c][find_right(p)];
					ans = max(ans, total - sum);
				}
			}
		}
	}
}

void process() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			for (int p = 0; p < 4; p++) {
				if (p == i || p == j) continue;
				for (int q = 0; q < 4; q++) {
					if (q == i || q == j || q == p) continue;
					solve(i, j, p, q);
				}
			}
		}
	}
}


int main() {
	fast;
	//fre();
	readINP();
	init_all_tt();
	/*for (int i = 0; i < 24; i++) {
		cout << i << '\n';
		cout << "above :" << " " << ss[0][find_above(i)] << '\n';
		cout << "below : " << ss[0][find_below(i)] << '\n';
		cout << "right : " << ss[0][find_right(i)] << '\n';
		cout << "left : " << ss[0][find_left(i)] << '\n';
		cout << "//##############################################################################" << '\n';
	}*/
	process();
	cout << (ans == 0 ? -1 : ans);
}
 