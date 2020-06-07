// Refer Discussion of codeforces

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N (int)3e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

int n, m;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int a[n];
  forn(i, n)
          cin >>
      a[i];
  int ans = -1;
  int mid;
  int l = 0, r = 300000;
  while (l <= r)
  {
    mid = l + (r - l) / 2;
    bool flag = true;
    int cur = 0;
    forn(i, n)
    {
      if (a[i] > cur)
      {
        int d = m - (a[i] - cur);
        // may be due to observation
        // As it is already greater than cur, no issues
        if (d > mid)
          cur = a[i];
      }
      else
      {
        int d = cur - a[i];
        // Mandatory
        if (d > mid)
        {
          flag = false;
          break;
        }
      }
    }
    if (flag)
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
