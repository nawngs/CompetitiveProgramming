#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], cnt[1000006];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for(int i = 1e6; i >= 1; i --){
		int maxa = 0;
		for(int j = 2 * i; j <= 1e6; j += i) maxa = max(maxa, cnt[j]);
		cnt[i] += maxa;
	}
	int ans = 0;
	for(int i = 1; i <= 1e6; i++) ans = max(ans, cnt[i]);
	cout << n - ans;
} 