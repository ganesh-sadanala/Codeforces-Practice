/*
Answer for n is odd is easy -> I got the idea
Failed to get the ans when n is even
Simple idea is ans will be with in
100 last numbers (get the idea based on the constraints)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve()
{
  int n;
  cin >> n;
  ll ans = 1;
  if (n < 3)
  {
    cout << n << endl;
    return;
  }
  if (n % 2)
  {
    ans = (ll)n * (ll)(n - 1) * (ll)(n - 2);
    cout << ans << endl;
    return;
  }
  for (ll i = n; i >= max(1, n - 100); i--)
  {
    for (ll j = n; j >= max(1, n - 100); j--)
    {
      for (ll k = n; k >= max(1, n - 100); k--)
      {
        ll temp1 = (i * j) / gcd(i, j);
        ll temp2 = (temp1 * k) / gcd(temp1, k);
        ans = max(ans, temp2);
      }
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
