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

int m, n, k;

bool check[1003][1003];

vector < pii > deleted;

bool check_valid(pii x) {
	if (x.fi < 1 || x.fi > m || x.se < 1 || x.se > n) return false;
	return true;
}

int main() {
	fast;
	cin >> m >> n >> k;	
	memset(check, 1, sizeof(check));
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		deleted.push_back({x, y});
		check[x][y] = false;
	}
	ll total = 0;
	for (int r = 1; r <= min(n, m) - 1; r++) total += 1ll * r * 1ll * (n - r) * 1ll * (m - r);

	//dinh xoa la A 

	for (auto A : deleted) {
		int x = A.fi;
		for (int r = 1; r <= min(n, m) - 1; r++) {
			for (int h = 0; h < r; h++) {
				int y = A.se - h;
				pii B = {x + h, y + r};
				pii C = {x + r, y + r - h};
				pii D = {x + r - h, y};
				if (!check_valid(A) || !check_valid(B) || !check_valid(C) || !check_valid(D)) continue;
				total --;
			}
		}
	}

	// dinh xoa la B

	for (auto B : deleted) {
		for (int r = 1; r <= min(n, m) - 1; r++) {
			for (int h = 0; h < r; h++) {
				int x = B.fi - h;
				int y = B.se - r;
				pii A = {x, y + h};
				pii C = {x + r, y + r - h};
				pii D = {x + r - h, y};
				if (!check_valid(A) || !check_valid(B) || !check_valid(C) || !check_valid(D) || !check[A.fi][A.se]) continue;
				total --;
			}
		}
	}

	// dinh xoa la C

	for (auto C : deleted) {
		for (int r = 1; r <= min(n, m) - 1; r++) {
			for (int h = 0; h < r; h++) {
				int x = C.fi - r;
				int y = C.se + h - r;
				pii A = {x, y + h};
				pii B = {x + h, y + r};
				pii D = {x + r - h, y};
				if (!check_valid(A) || !check_valid(B) || !check_valid(C) || !check_valid(D) || !check[A.fi][A.se] || !check[B.fi][B.se]) continue;
				total --;
			}
		}
	}

	// dinh xoa la D

	for (auto D : deleted) {
		for (int r = 1; r <= min(n, m) - 1; r++) {
			for (int h = 0; h < r; h++) {
				int x = D.fi + h - r;
				int y = D.se;
				pii A = {x, y + h};
				pii B = {x + h, y + r};
				pii C = {x + r, y + r - h};
				if (!check_valid(A) || !check_valid(B) || !check_valid(C) || !check_valid(D) 
				|| !check[A.fi][A.se] || !check[B.fi][B.se] || !check[C.fi][C.se]) continue;
				total --;			
			}
		}
	}
	cout << total;
}
