#include <bits/stdc++.h>

using namespace std;

int ntest;
long long n, a[100005], pos[200005],ans = 0;

int main(){
	cin >> ntest;
	while(ntest --){
		memset(a, 0, sizeof(a));
		memset(pos, 0, sizeof(pos));
		cin >> n;
		//n = 1e5;
		ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			//a[i] = i;
			//b[i] = a[i];
			pos[a[i]] = i;
		}
		sort(a + 1, a + n + 1);
		long long cuoi = n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= cuoi; j++){
				if(i == j) continue;
				if(a[i] * a[j] >= 2 * n){
					cuoi = j;
					break;
				}
				if(a[i] * a[j] == pos[a[i]] + pos[a[j]]) ans ++;
			}
		}
		cout << ans / 2 << '\n';
	}
}