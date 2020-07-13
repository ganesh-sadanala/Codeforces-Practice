// Refer:https://codeforces.com/blog/entry/21885?#comment-265815
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"

const int N = 1e5 + 5;
int dp[N][3][2];
int n;
string str;
vector<int> a;
// Normal question + state
// state => 0(pre is not in the inversion string range),
// 1(pre is in the inv range), 2(after the inv range)
int solve(int x, int state, int pre)
{
  if (x == n)
    return 0;
  int res = 0;
  if (dp[x][state][pre] != -1)
    return dp[x][state][pre];
  if (!x)
  {
    if (state == 0)
      res = max(res, max(solve(x + 1, 0, a[x]), solve(x + 1, 1, !a[x])));
    else if (state == 1)
      res = max(res, max(solve(x + 1, 1, !a[x]), solve(x + 1, 2, a[x])));
    res++;
  }
  else
  {
    if (state == 0)
    {
      res = max(res, max(solve(x + 1, 0, pre), solve(x + 1, 0, a[x]) + (pre != a[x])));
      res = max(res, max(solve(x + 1, 1, !pre), solve(x + 1, 1, !a[x]) + (pre != (!a[x]))));
    }
    else if (state == 1)
    {
      res = max(res, max(solve(x + 1, 1, pre), solve(x + 1, 1, !a[x]) + (pre != (!a[x]))));
      res = max(res, max(solve(x + 1, 2, !pre), solve(x + 1, 2, a[x]) + (pre != a[x])));
    }
    else
      res = max(res, max(solve(x + 1, 2, pre), solve(x + 1, 2, a[x]) + (pre != a[x])));
  }
  dp[x][state][pre] = res;
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  forn(i, N)
      forn(j, 3)
          forn(k, 2)
              dp[i][j][k] = -1;
  cin >> n;
  cin >> str;
  forn(i, n)
  {
    if (str[i] == '0')
      a.pb(0);
    else
      a.pb(1);
  }
  cout << max(max(solve(0, 0, !a[0]), solve(0, 1, a[0])), max(solve(0, 0, a[0]), solve(0, 1, !a[0]))) << endl;
}
