// lazy
#include <bits/stdc++.h>

using namespace std;

int n, it[8000005], lazy[8000005], a[1005], b[1005];

void update(int node, int l, int r, int x, int y){
	if(lazy[node] != 0){
		it[node] += lazy[node];
		if(l < r){
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(r < x || y < l || l > r) return ;
	if(x <= l && r <= y){
		it[node] += r - l + 1;
		if(l < r){
			lazy[node * 2] ++;
			lazy[node * 2 + 1] ++;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, x, y);
	update(node * 2 + 1, mid + 1, r, x, y);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int x, int y){
	if(r < x || y < l || l > r) return 0;
	if(lazy[node] != 0){
		it[node] += lazy[node];
		if(l < r){
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;	
	}
	if(x <= l && r <= y) return it[node]; 
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, x, y) + query(node * 2 + 1, mid + 1, r, x, y);

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		update(1, 1, 1e6, a[i], b[i]);
	}
	int maxa = query(1, 1, 1e6, 1, 1);
	int pos = 1;
	for(int i = 2; i <= 1e6; i++){
		int tmp = query(1, 1, 1e6,i, i);
		if(maxa < tmp){
			maxa = tmp;
			pos = i;
		}
	}
	cout << maxa << '\n';
	for(int i = 1; i <= n; i++){
		if(a[i] <= pos && pos <= b[i]) cout << i << '\n';
	}
}

/*
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1007], b[1007];
int c[1000007];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(c, 0, sizeof(c));
    c[0] = -1;
    int pos = 0;
    for(int i = 1; i <= n; i++) 
        {
            cin >> a[i] >> b[i];
            c[a[i]]++;
            c[b[i] + 1]--;
        }
    int sum = 0;
    for(int i = 1; i <= 1e6; i++)
    {
        sum += c[i];
        if(sum > c[pos]) pos = i;
        c[i] = sum;
    }
    cout << c[pos] << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= pos && pos <= b[i]) cout << i << '\n';
    }
    return 0;

}*/