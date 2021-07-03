#include <bits/stdc++.h>
using namespace std;
int n;
long long b[100007];
long long dev(int x)
{
	long long s = 1;
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0)
		{
			s += i;
			break;
		}
	if(s == 1) s += x;
	s = s * s;
	return s;
}
pair < long long , long long > seg[400040];
void build(int l, int r, int node)
{
	if(l == r)
	{
		seg[node] = {b[l] , b[l]};
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, node*2);
	build(mid + 1, r, node*2 + 1);
	seg[node] = {max(seg[node*2].first , seg[node*2 + 1].first) , min(seg[node*2 + 1].second , seg[node*2].second)};
}
pair < long long , long long > get(int u, int v, int l, int r, int node)
{
	if(r < u || v < l) return {-1e18, 1e18};
	if(u <= l && r <= v) return seg[node];
	int mid = (l + r)/2;
	auto z1 = get(u, v, l, mid, node*2);
	auto z2 = get(u , v, mid + 1, r, node*2 + 1);
	return {max(z1.first , z2.first) , min(z1.second, z2.second)};
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("DEVI.inp","r",stdin);
	freopen("DEVI.out","w",stdout);
	int ntest;
	cin >> n >> ntest;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		b[i] = dev(a);
	}
	build(1, n, 1);
	while(ntest--)
	{
		long long q;
		cin >> q;
		int ans = 0;
		int dau = 1;
		int cuoi = 0;
		//long long maxi = -1e18;
		//long long mini = 1e18;
		while(cuoi < n)
		{
			cuoi++;
			auto x = get(dau, cuoi, 1, n, 1);
			if(x.first - x.second > q) 
			{
				while(dau <= cuoi)
				{
					x = get(dau, cuoi, 1, n ,1);
					if(x.first - x.second > q)
					{
						dau++;
					}
					else break;
				}
				ans = max(ans, cuoi - dau + 1);
			}
			else ans = max(ans, cuoi - dau + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}