// Refer: AshishGup
// Solve a lot of similar pbms
// similar to lis -> slightly different
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"

void solve()
{
  int n;
  cin >> n;
  int a[n];
  int ans[n + 1];
  forn(i, n)
  {
    cin >> a[i];
    ans[i] = 0;
  }
  ans[n] = 0;
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    ans[a[i]] = max(ans[a[i]], ans[a[i] - 1] + 1);
    res = max(res, ans[a[i]]);
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
