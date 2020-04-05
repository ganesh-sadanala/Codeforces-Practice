/*
    YES PAIN YES GAIN
*/

//Although i solved in a different way my approach is slightly different and longer than this approach, learned:Nice think backwards also
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=2e5+5;
const int M=3e5;
const int mod=1e9+7;

void solve()
{
    int n,a;
    cin>>n;

    vi freq(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        freq[a]++;
    }

    sort(r_all(freq));

    int ans=freq[0];
    for(int i=1;i<=n;i++)
    {
        if(freq[i]>=freq[i-1]) freq[i]=max(0ll,freq[i-1]-1);
        ans+=freq[i];
    }

    cout<<ans<<"\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}
