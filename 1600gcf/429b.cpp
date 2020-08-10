// Refer: Editorial
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
  int n, m;
  cin >> n >> m;
  int mat[n + 2][m + 2];
  int dp1[n + 2][m + 2];
  int dp2[n + 2][m + 2];
  int dp3[n + 2][m + 2];
  int dp4[n + 2][m + 2];
  for (int i = 0; i <= n + 1; i++)
  {
    for (int j = 0; j <= m + 1; j++)
    {
      dp1[i][j] = 0;
      dp2[i][j] = 0;
      dp3[i][j] = 0;
      dp4[i][j] = 0;
      mat[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> mat[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp1[i][j] = mat[i][j] + max(dp1[i][j - 1], dp1[i - 1][j]);
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      dp2[i][j] = mat[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);

  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      dp3[i][j] = mat[i][j] + max(dp3[i][j - 1], dp3[i + 1][j]);

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      dp4[i][j] = mat[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

  int ans = 0;
  for (int i = 2; i < n; i++)
  {
    for (int j = 2; j < m; j++)
    {
      ans = max(ans, max(dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j],
                         dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]));
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
