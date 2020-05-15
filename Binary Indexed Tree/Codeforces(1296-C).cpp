/*
    হ্যাঁ এটাই সাইন্স!!!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define S second
#define F first
#define pb push_back
#define mem(a, b)     memset(a, b, sizeof(a))
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define BaChao     ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX = 1e5+10;


void update(map<ll,ll>&val,ll idx,ll x,ll n)
{
    while(idx <= n)
    {
        val[idx] += x;
        idx += idx&(-idx);
    }
}
ll query(map<ll,ll>&val,ll idx)
{
    ll sum = 0;
    while(idx > 0)
    {
        sum += val[idx];
        idx -= idx&(-idx);
    }
    return sum;
}
int main()
{
    ll t,n,type,val,m,k,now,p,q,cas=1;
    map<ll,ll>tree,work;
    cin>>n>>m>>k;
    ll a[n+2];
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    ll x[m+2],y[m+2],d[m+2];
    x[0]=y[0]=d[0]=0;
    for(ll i=1; i<=m; i++)
    {
        cin>>x[i]>>y[i]>>d[i];
    }

    while(k--)
    {
        cin>>p>>q;
        //SegmentWise Update
        update(work,p,1ll,m);
        update(work,q+1,-1ll,m);
    }
    for(int i=1; i<=m; i++)
    {
        now=query(work,i);
        update(tree,x[i],now*d[i],n);
        update(tree,y[i]+1,-1ll*(now*d[i]),n);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<a[i]+query(tree,i)<<" ";
    }
    cout<<endl;

}
