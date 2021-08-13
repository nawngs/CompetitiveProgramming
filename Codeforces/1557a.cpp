#include <bits/stdc++.h>

using namespace std;

int ntest;

long long n, a[100005];

int main(){
	cin >> ntest;
	while(ntest --){
		cin >> n;
		long long s = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			s += a[i];
		}
		sort(a + 1, a + n + 1);
		  cout << fixed << setprecision(8) << (long double) a[n] + (long double) (s - a[n]) / (n - 1) << '\n';
	}
}