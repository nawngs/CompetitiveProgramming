#include <bits/stdc++.h>

using namespace std;

long long n, mod;

struct matran
{
	long long c[3][3];
	matran(){
		c[0][0] = 0;
		c[0][1] = 1;
		c[1][0] = 1;
		c[1][1] = 1;
	}
};

matran nhan(matran a, matran b){
	matran res;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			res.c[i][j] = 0;
			for(int k = 0; k <= 1; k++){
				res.c[i][j] = (res.c[i][j] + ((a.c[i][k] % mod) * (b.c[k][j] % mod)) % mod) % mod;
			}
		}
	}
	return res;
}

matran po(matran a, long long n){
	if(n == 1) return a;
	matran ha = po(a, n / 2);
	ha = nhan(ha, ha);
	if(n % 2 == 1) ha = nhan(ha, a);
	return ha;
}

int main(){
	cin >> n >> mod;
	n = (2 * (n - 1)) - 1;
	matran f, tam = po(f, n);
	cout << tam.c[0][1] << '\n';	
}
