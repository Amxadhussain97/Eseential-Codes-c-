/*
    হ্যাঁ এটাই সাইন্স!!!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define S second
#define F first
#define mem(a, b)     memset(a, b, sizeof(a))
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define BaChao     ios_base::sync_with_stdio(false);cin.tie(NULL);


/*
Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag).
        lower_bound() works as upper_bound() and vice-versa.
        Be careful to use.
        i) find_by_order(k) : kth smallest element counting from 0 .
        ii) order_of_key(k) : number of elements strictly smaller than k.
*/

/******************************************
#Rows are numbered from top to bottom.
#Columns are numbered from left to right.
Moves : L, U, R, D, LU, RU, RD, LD.
Lower bound e >=
Upper bound e >b
******************************************/

/*...... ! Code starts from here ! ......*/

struct tt
{
    int p,l,r;
};
bool operator<(tt a,tt b){
    if (a.p!=b.p) return a.p<b.p;//Boro Theke Chuto
    else return a.l>b.l;//ChutoThekeBoro

}
int main()
{
    ll sum,ans,cell,seg,middle,t,n,m,p,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+2],wow=1;
        memset(a,0,sizeof(a));
        priority_queue<tt>pq;
        pq.push({n,1,n});
        while(pq.top().p>=2 && !pq.empty())
        {
            tt now=pq.top();
            pq.pop();
            middle=(now.r+now.l)/2;
            a[middle]=wow;
            seg=now.r-now.l+1;
            if(seg%2==0)
            {
                pq.push({(seg/2)-1,now.l,middle-1});
                pq.push({(seg/2),middle+1,now.r});
            }
            else
            {
                pq.push({seg/2,now.l,middle-1});
                pq.push({(seg/2),middle+1,now.r});
            }
            wow++;
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]==0)
            {
                a[i]=wow;
                wow++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
