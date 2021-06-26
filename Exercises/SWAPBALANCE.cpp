#include <bits/stdc++.h>

using namespace std;

long long n, m, a[2005], b[2005], suma = 0, sumb = 0, dema = 0, demb = 0, c[4000005], d[4000005];

long long bs1(long long x){
	long long l = 1, r = demb, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(2 * d[mid] >= x){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

long long bs2(long long x){
	long long l = 1, r = demb, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(2 * d[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SWAPBALANCE.inp", "r", stdin);
	freopen("SWAPBALANCE.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		suma += a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		sumb += b[i];
	}
	long long res = abs(suma - sumb);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) res = min(res, abs(suma + b[j] - a[i] - (sumb + a[i] - b[j])));

	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)  c[++ dema] = a[i] + a[j];
	for(int i = 1; i < m; i++)
		for(int j = i + 1; j <= m; j++)  d[++ demb] = b[i] + b[j];
	sort(c + 1, c + dema + 1);
	sort(d + 1, d + demb + 1);
	for(int i = 1; i <= dema; i++){
		long long tmp = bs1((sumb - suma + 2 * c[i])), tmp2 = bs2((sumb - suma + 2 * c[i]));
		if(tmp != -1) res = min(res, abs(sumb + c[i] - d[tmp] - (suma - c[i] + d[tmp])));
		if(tmp2 != -1) res = min(res, abs(sumb + c[i] - d[tmp2] - (suma - c[i] + d[tmp2])));
	}
	cout << res << '\n';
}