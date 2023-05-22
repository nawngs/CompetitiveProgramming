#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7;

long long n, a[105], f[nmax + 7], cnt[nmax + 7], maxa[nmax + 7];

void sang(){
	for(int i = 1; i <= nmax; i++) f[i] = i;
	for(int i = 2; i * i <= nmax; i++)
		if(f[i] == i) for(int j = i * 2; j <= nmax; j += i) f[j] = i; 
}

long long mu(int a, int b){
	if(b == 0) return 1;
	long long x = mu(a, b / 2);
	x *= x;
	if(b % 2 == 1) x *= a;
	return x;
}

int main(){
	cin >> n;
	//n = 100;
	if(n == 0){
		cout << "impossible";
		return 0;
	}
	sang();
	bool th = false;
	//cout << f[8] << '\n'
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 0){
			th = true;
		}
		long long dem = 0;
		int x = a[i];
		int pre = 0;
		while(x > 1){
			if(f[x] != pre) {
				cnt[pre] += dem;
				maxa[pre] = max(maxa[pre], dem);
				pre = f[x];
				dem = 1;
			}
			else dem ++;
			x /= f[x];
		}
		//cout << dem << '\n';
		cnt[pre] += dem;
		maxa[pre] = max(maxa[pre], dem);

	}
	long long res = 1;
	if(th){
		cout << "impossible" << '\n';
		return 0;
	}
	//cout << cnt[2] << '\n';
	for(int i = 1; i <= nmax; i++) res *= mu(i, cnt[i] - maxa[i]);
	//cout << ans;
	cout << res;
}