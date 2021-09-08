#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, a[2005], p[2005];

pair < vector < int >, int > f[2005];

pair < int, int > ans[2005];

bool cmp(pair < vector < int >, int >  x, pair < vector < int >, int >  y) {
	vector < int > temp1 = x.fi;
	vector < int > temp2 = y.fi;
	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end());
	for (int i = 1; i < temp1.size(); i++) {
		if (temp1[i] == temp1[i - 1]) {
			temp1[i] ++;
			temp1[i - 1] = -1;
		}
		if (temp2[i] == temp2[i - 1]) {
			temp2[i] ++;
			temp2[i - 1] = -1;
		}
	}
	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end());
	for (int i = temp1.size() - 1; i >= 0; i--) {
		if (temp1[i] > temp2[i]) return false;
		if (temp2[i] > temp1[i]) return true;
	}
	return true;
}

void create(pair < vector < int >, int > g[2005]) {
	for (int i = 1; i <= n; i++) {
		g[i].fi = f[i].fi;
		g[i].se = f[i].se;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i].fi.push_back(a[i]);
		f[i].se = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[i].fi.push_back(p[i]);
		f[i].se = i;
	}
	sort(f + 1, f + n + 1, cmp);
	//for (int i = 1; i <= n; i++) cout << f[i].se << '\n';
	for (int i = 1; i <= n; i++) {
		pair < vector < int >, int > temf[2005];
		create(temf);
		int tam = n - 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) temf[j].fi.push_back(n);
			else {
				temf[j].fi.push_back(tam);
				tam --;
			}
		}
		sort(temf + 1, temf + n + 1, cmp);
		for (int j = 1; j <= n; j++) 
			if (temf[j].se == f[i].se) {
				ans[f[i].se].se = j;
				break;
			}
	}
	for (int i = 1; i <= n; i++) {
		pair < vector < int >, int > temf[2005];
		create(temf);
		int tam = 2;
		for (int j = n; j >= 1; j--) {
			if (i == j) temf[j].fi.push_back(1);
			else {
				temf[j].fi.push_back(tam);
				tam ++;
			}
		}
		sort(temf + 1, temf + n + 1, cmp);
		for (int j = 1; j <= n; j++) 
			if (temf[j].se == f[i].se) {
				ans[f[i].se].fi = j;
				break;
			}
	}
	for (int i = 1; i <= n; i++) cout << ans[i].fi << " " << ans[i].se << '\n';
}