// link: https://drive.google.com/file/d/1snly0Tds3MmdStbv6WhidFBlVwmMrD1v/view

#include <bits/stdc++.h>

using namespace std;

const int nmax = 435;

int n, k, f[nmax + 5];

void sang_uoc(){
	for(int i = 1; i <= nmax; i++) f[i] = 1;
	for(int i = 2; i * i <= nmax; i++){
		if(f[i] == 1){
			for(int j = i * 2; j <= nmax; j+= i) f[j] = i;
		}
	}
	for(int i = 1; i <= nmax; i++) if(f[i] == 1) f[i] = i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sang_uoc();
	while(cin >> n >> k){
		int a[nmax + 5];
		memset(a, 0, sizeof(a));
		for(int i = k + 1; i <= n; i++){
			int temp = i;
			while(temp > 1){
				a[f[temp]] ++;
				temp /= f[temp];
			}
		}
		for(int i = 1; i <= n - k; i++){
			int temp = i;
			while(temp > 1){
				a[f[temp]] --;
				temp /= f[temp];
			}
		}
		unsigned long long ans = 1;
		for(int i = 1; i <= nmax; i++){
			if(a[i] >= 0) ans *= a[i] + 1;
		}
		cout << ans << '\n';
	}
}