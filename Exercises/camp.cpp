#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

long long m, n, f[1005][1005][3];

pair < long long, long long > hn[1005], hcm[1005];

long long calc_dis(long long a, long long b, long long c, long long d){
	return (a - c) * (a - c) + (b - d) * (b - d);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("camp.Inp", "r", stdin);
	freopen("camp.Out", "w", stdout);
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> hn[i].fi >> hn[i].se;
	for(int i = 1; i <= n; i++) cin >> hcm[i].fi >> hcm[i].se;

	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= n; j++) 
			for(int k = 1; k <= 2; k++) f[i][j][k] = 1e18;
	//f[1][1][2] = calc_dis(hn[1].fi, hn[1].se, hcm[1].fi, hcm[1].se);
	f[1][0][1] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			f[i + 1][j][1] = min(f[i + 1][j][1], min(f[i][j][1] + calc_dis(hn[i].fi, hn[i].se, hn[i + 1].fi, hn[i + 1].se), 
													f[i][j][2] + calc_dis(hcm[j].fi, hcm[j].se, hn[i + 1].fi, hn[i + 1].se)));
			//################################################################################################################################
			f[i][j + 1][2] = min(f[i][j + 1][2], min(f[i][j][1] + calc_dis(hn[i].fi, hn[i].se, hcm[j + 1].fi, hcm[j + 1].se), 
													f[i][j][2] + calc_dis(hcm[j].fi, hcm[j].se, hcm[j + 1].fi, hcm[j + 1].se)));
			//cout << i << " " << j << " " << f[i][j][1] << " " << f[i][j][2] << '\n';
		}
	}
	cout << f[m][n][1];
}
