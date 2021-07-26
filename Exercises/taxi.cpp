#include <bits/stdc++.h>

using namespace std;

long long n, x[5005], y[5005];

double f[5005][5005], ans = 1e18;

double calc_dis(long long a, long long b, long long c, long long d){
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("taxi.Inp", "r", stdin);
	freopen("taxi.Out", "w", stdout);
	cin >> n;
	for(int i = 0; i <= n; i++) 
		for(int j = 0; j <= n; j++) f[i][j] = 1e18;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	f[0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			f[j][j + 1] = min(f[j][j + 1], f[i][j] + calc_dis(x[i], y[i], x[j + 1], y[j + 1]));
			f[i][j + 1] = min(f[i][j + 1], f[i][j] + calc_dis(x[j], y[j], x[j + 1], y[j + 1]));
			if(j == n) ans = min(ans, f[i][j]);
		}
	}
	cout << fixed << setprecision(3) << ans;
}
