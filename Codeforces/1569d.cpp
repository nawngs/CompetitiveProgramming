#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair < int, int >

using namespace std;

int t, n, m, k, x;

pii p[100005];
	
vector < int > sub_ver[1000005], sub_hor[1000005];

void sol() {
	cin >> n >> m >> k;
	vector < pii > ver, hor;
	vector < int > a, b, cnt_ver, cnt_hor;
	a.clear();
	b.clear();
	cnt_ver.clear();
	cnt_hor.clear();
	ver.clear();
	hor.clear();
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 1; i <= m; i++) {
		cin >> x;
		b.push_back(x);
	}
	if (a[a.size() - 1] != 1000000) {
		a.push_back(1000000);
		++ n;
	}
	if (b[b.size() - 1] != 1000000) {
		b.push_back(1000000);
		++ m;
	}
	for (int i = 0; i <= 1000003; i++) {
		cnt_ver.push_back(0);
		cnt_hor.push_back(0);
		sub_hor[i].clear();
		sub_ver[i].clear();
	}
	for (int i = 1; i <= k; i++) {
		cin >> p[i].fi >> p[i].se;
		int tmpa = lower_bound(a.begin(), a.end(), p[i].fi) - a.begin();
		int tmpb = lower_bound(b.begin(), b.end(), p[i].se) - b.begin();
		if (a[tmpa] == p[i].fi && b[tmpb] == p[i].se) continue;
		if (a[tmpa] == p[i].fi) {
			ver.push_back({p[i].se, p[i].fi});
			sub_ver[p[i].fi].push_back(p[i].se);
			cnt_ver[p[i].se] ++;
		}
		if (b[tmpb] == p[i].se) {
			hor.push_back({p[i].fi, p[i].se});
			sub_hor[p[i].se].push_back(p[i].fi);
			cnt_hor[p[i].fi] ++;
		}
	}
	sort(ver.begin(), ver.end());
	sort(hor.begin(), hor.end());
	for (int i = 1; i <= 1000000; i++) {
		cnt_hor[i] += cnt_hor[i - 1];
		cnt_ver[i] += cnt_ver[i - 1];
	}
	long long ans = 0;
	for (int i = 0; i < (int) ver.size(); i++) {
		int tam = lower_bound(b.begin(), b.end(), ver[i].fi) - b.begin();
		if (tam >= (int) b.size() || tam < 0) continue;
		ans += cnt_ver[b[tam] - 1] - cnt_ver[ver[i].fi];
		int l = lower_bound(sub_ver[ver[i].se].begin(), sub_ver[ver[i].se].end(), ver[i].fi) - sub_ver[ver[i].se].begin();
		int r = lower_bound(sub_ver[ver[i].se].begin(), sub_ver[ver[i].se].end(), b[tam]) - sub_ver[ver[i].se].begin();
		//r --;
		cout << sub_ver[ver[i].se].size() << " " << ver[i].se << " " << ver[i].se << " " << b[tam] << " " << l << " " << r << '\n';
		if (l >= (int) sub_ver[ver[i].se].size() || l < 0
      	|| r >= (int) sub_ver[ver[i].se].size() || r < 0 || l > r) continue;
		ans = ans - (r - l);
	}
	//cout << ans << '\n';
	for (int i = 0; i < (int) hor.size(); i++) {
		int tam = lower_bound(a.begin(), a.end(), hor[i].fi) - a.begin();
		if (tam >= a.size() || tam < 0) continue;
		ans += cnt_hor[a[tam] - 1] - cnt_hor[hor[i].fi];
		int l = lower_bound(sub_hor[hor[i].se].begin(), sub_hor[hor[i].se].end(), hor[i].fi) - sub_hor[hor[i].se].begin();
		int r = lower_bound(sub_hor[hor[i].se].begin(), sub_hor[hor[i].se].end(), a[tam]) - sub_hor[hor[i].se].begin();
		r --;
		if (l >= (int) sub_hor[hor[i].se].size() || l < 0
      	|| r >= (int) sub_hor[hor[i].se].size() || r < 0 || l > r) continue;
		//cout << hor[i].fi << " " << hor[i].se << " " << a[tam] << " " << l << " " << r << '\n';
		ans = ans - (r - l);
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}
