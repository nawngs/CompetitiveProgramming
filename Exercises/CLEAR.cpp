#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int l, r, check[1005];

int calc(int x){
	int sum = 0;
	while(x > 0){
		sum += (x % 10) * (x % 10);
		x /= 10;
	}
	return sum;
}

void build_check(){
	check[1] = 1;
	for(int i = 2; i <= 1000; i++){
		vector < int > tmp;
		int x = i;
		while(check[x] == -1){
			check[x] = 0;
			tmp.push_back(x);
			x = calc(x);

		}
		for(auto v : tmp) check[v] = check[x];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("CLEAR.inp", "r", stdin);
	freopen("CLEAR.out", "w", stdout);
	cin >> l >> r;
	/*
	clock_t start, end;   
    double time_use;     
    start = clock();
    */
    
	memset(check, 255, sizeof(check));
	build_check();
	//for(int i = 1; i <= r; i++) cout << check[i] << '\n';
	int ans = 0;
	for(l; l <= r; l ++) if(check[calc(l)] == 1) ans ++;
	cout << ans << '\n';
	/*end = clock();
	time_use = double(end - start) / CLOCKS_PER_SEC;
	cout << time_use;
	*/
}