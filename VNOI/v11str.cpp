//Z_function
#include <bits/stdc++.h>

using namespace std;

int np, nt, a[1005], b[500005], c[501005], c_rev[501005], z[501005], z_rev[501005];

void build_z(int a[], int n, int z[]){
	z[0] = n;
	int l, r;
	l = r = -1;
	for(int i = 1; i < n; i++){
		if(i > r){
			l = i; r = i - 1;
			while(r < n - 1 && a[r + 1] == a[r - l + 1]) r ++;
			z[i] = r - l + 1;
		}
		else{
			if(z[i - l] < r - i + 1) z[i] = z[i - l];
			else{
				l = i;
				while(r < n - 1 && a[r + 1] == a[r - l + 1]) r++;
				z[i] = r - l + 1;
			}
		}
	}
}

int main(){
	cin >> np >> nt;
	for(int i = 1; i <= np; i++) cin >> a[i];
	for(int i = 1; i <= nt; i++) cin >> b[i];
	for(int i = 0; i < np; i++) c[i] = a[i + 1];
	c[np] = -1;
	for(int i = 1; i <= nt; i++) c[np + i] = b[i];
	for(int i = np; i >= 1; i--) c_rev[np - i] = a[i];
	c_rev[np] = -1;
	for(int i = nt; i >= 1; i--) c_rev[np + 1 + nt - i] = b[i];
	//for(int i = 0; i < np + nt + 1; i ++) cout << c[i] << " ";
	//cout << '\n' << "#######################################################" << '\n';
//	for(int i = 0; i < np + nt + 1; i++) cout << c_rev[i] << " ";
//	cout << '\n' << "#######################################################" << '\n';
	int c_size = np + nt + 1;
	build_z(c, c_size, z);
	build_z(c_rev, c_size, z_rev);
//int ans = 0;
	for(int i = np + 1; i < c_size - np + 1; i++){
		if(z[i] >= np){
			cout << i - np << '\n';
			return 0;
		}
		else{
			int last = i + np - 1;
			int last_rev = nt - (last - np) + 1 + np;
			if(z_rev[last_rev] + z[i] + 1 >= np){
				cout << i - np << '\n';
				return 0;
			}
		}
	}
	cout << -1;
}