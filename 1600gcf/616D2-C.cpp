// Refer Editorial
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 2e5 + 5;
void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  int a[n];
  forn(i, n)
          cin >>
      a[i];

  int before = m - 1;
  int control = min(before, k);
  int res = -1;
  for (int x = 0; x <= control; x++)
  {
    int str_ans = 1e9 + 1;
    for (int y = 0; y <= before - control; y++)
    {
      int case_ans = max(a[x + y], a[x + y + n - m]);
      str_ans = min(str_ans, case_ans);
    }
    res = max(str_ans, res);
  }
  cout << res << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
}
