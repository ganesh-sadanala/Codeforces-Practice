// Refer: Editorial
// Refer: tourist answer
// Name itself suggets the answer
// Similar to LIS DP
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"

const int maxn = 1e6 + 5;
int dp[maxn];
int b[maxn];
void solve()
{
  int n;
  cin >> n;
  forn(i, n)
  {
    int a;
    cin >> a;
    cin >> b[a];
  }
  int res = 0;
  if (b[0] > 0)
    dp[0] = 1;
  for (int i = 1; i < maxn; i++)
  {
    if (b[i] == 0)
      dp[i] = dp[i - 1];
    else
    {
      if (b[i] >= i)
        dp[i] = 1;
      else
        dp[i] = dp[i - b[i] - 1] + 1;
    }
    if (res < dp[i])
      res = dp[i];
  }
  cout << n - res << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
