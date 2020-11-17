#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

ll c[1000001];
const int N = 2e5 + 5;
void solve()
{
  int k;
  cin >> k;
  ll total = 0;
  int l = 0, r = 0;
  string s;
  cin >> s;
  int len = s.size();
  if (k == 0)
  {
    int inx = 0;
    ll cnt = 0;
    while (inx < len)
    {
      cnt = 0;
      while (inx < len && s[inx] != '1')
      {
        cnt++;
        inx++;
      }
      // cout<<cnt<<" "<<inx<<endl;
      inx++;
      total += (cnt * (cnt + 1)) / 2;
    }
    cout << total << endl;
  }
  else
  {
    c[0] = 1;
    int p = 0;
    // simple maths
    // left end and right end
    forn(i, len)
    {
      p += (s[i] == '1');
      c[p]++;
    }
    ll ans = 0;
    for (int i = k; i <= len; i++)
    {
      ans += c[i] * c[i - k];
    }
    cout << ans << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin>>t;
  // while(t--)
  solve();
}
