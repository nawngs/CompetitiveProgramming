#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>struct segtree{
    const T ID=0; T comb(T a, T b){return a+b;};
    ll n_; vector<T>seg;
    void buildtree(ll n__){n_=n__;seg.assign(4*n_, ID);};
    void process(ll idx){cout<<seg[idx]<<" ";};
    void update(ll root, ll l, ll r, ll pos, ll val){
        if (pos<l || pos>r) return;
        if (l==r){seg[root]=val; return;};
        ll mid=(l+r)/2;
        update(2*root, l, mid, pos, val);
        update(2*root+1, mid+1, r, pos, val);
        seg[root]=comb(seg[2*root], seg[2*root +1]);
    }
    T getsum(ll root, ll l, ll r, ll u, ll v){
        if (v<l || u>r) return 0;//node nam ngoaif khoang can tinh
        if (u<=l && r<=v) return seg[root];
        ll mid=(l+r)/2;
        return comb(getsum(2*root, l, mid, u, v) , getsum(2*root +1, mid+1, r, u, v));
    }
};
segtree<ll>st;
ll n, q;
ll a[200005];

int main(){
    cin>>n>>q;
    st.buildtree(n+1);
    for (int i=1;i <=n; i++){
        cin>>a[i];
        st.update(1, 1, n, i, a[i]);
    }
  	while (q--){
        ll command, c1, c2;
        cin>>command>>c1>>c2;
        if (command==1){
            st.update(1, 1, n, c1, c2);
        }else{
            cout<<st.getsum(1, 1, n, c1, c2)<<'\n';
        }
    }
}