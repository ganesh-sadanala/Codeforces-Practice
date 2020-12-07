#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 1e5 + 5;

void solve()
{
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> v;
    forn(i,n){
        ll x;
        cin>>x;
        v.pb(x);
    }

    vector<vector<ll>> vals(2e5 + 10);
    forn(i,n)
    {
        ll ele = v[i];
        ll cnt=0;
        while(ele > 0)
        {
            vals[ele].pb(cnt);
            ele /= 2;
            cnt++;
        }
    }

    ll ans = 1e9;
    for(int i=1;i<=2e5;i++)
    {
        sort(vals[i].begin(),vals[i].end());
        if(vals[i].size() < k)
            continue;

        ans = min(ans, (ll)accumulate(vals[i].begin(), vals[i].begin() + k, 0));
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
