// Editorial by Ashishgup

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 2e5 + 5;
int c[N];
int d[N];
int n;
ll val;

ll check(ll r)
{
    ll cur_div;
    for(int i=0;i<n;i++)
    {
        cur_div=1;
        if(r<1900)
            cur_div=2;
        if(cur_div!=d[i])
        {
            if(cur_div==2)
                return 0;
            else
                return -1;
        }
        r+=c[i];
    }
    val=r;
    return 1;
}

int solve()
{
    ll low=-1e8,high=1e8;
    ll ans=1900;
    while(low<high)
    {
        ll mid=(low+high+1)>>1;
        ll ch = check(mid);
        if(ch==-1)
        {
            high=mid-1;
        }
        else if(ch==0)
        {
            ans=mid+1;
            low=mid+1;
        }
        else{
            ans=mid;
            low=mid;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>c[i]>>d[i];
        if(d[i]==2)
            flag=false;
    }
    if(flag)
        cout<<"Infinity"<<endl;
    else{
        int ans=solve();
        if(check(ans)!=1)
            cout<<"Impossible"<<endl;
        else
            cout<<val<<endl;
    }
}
