// Refer: Editorial and codeforces Discuss
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 3501;

void solve()
{
  int n;
  cin >> n;
  ll res = 0;
  ll mod = 1e9 + 7;
  int p[n + 1];
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  int dp[n + 1];
  for (int i = 0; i <= n; i++)
    dp[i] = 0;
  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1;
    // Total number of steps to reach dp[i] from dp[i]
    // cost is usage of number of portals
    // LIS kind of thing
    // Graph based
    // a -> b -> c  then a -> c cost is a -> b cost + b -> c cost
    // +1 is to go from one to another
    for (int j = p[i]; j < i; j++)
      dp[i] = (dp[i] + dp[j] + 1) % mod;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + dp[i] + 1) % mod;
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
