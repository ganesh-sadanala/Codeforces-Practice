// Refer: Editorial ans Standings(Rock)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const ll N = 4e5 + 5;
ll a[N];

void solve()
{
  int n;
  ll I;
  cin >> n >> I;
  forn(i, n)
          cin >>
      a[i];

  sort(a, a + n);
  ll k = (8 * I) / n;
  ll K = pow(2ll, min(20ll, k));

  vector<ll> v;
  vector<ll> psum;
  // number of ele changed
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int j = i;
    ll cnt = 0;
    while (j < n && (a[i] == a[j]))
    {
      j++;
      cnt++;
    }
    v.pb(a[i]);
    psum.pb(cnt);
    i = j - 1;
  }

  if (K >= v.size())
    ans = 0;
  else
  {
    int sz = v.size();
    for (int i = 1; i < sz; i++)
      psum[i] += psum[i - 1];
    int i = 1, j = K;
    ans = psum[sz - 1] - psum[K - 1];
    while (j < sz)
    {
      ll temp = psum[sz - 1] - psum[j];
      temp += psum[i - 1];
      ans = min(ans, temp);
      i++;
      j++;
    }
  }
  cout << ans << endl;
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
