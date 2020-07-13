// Got the idea but forgot the LIS nlogn algo
// Just a Algo Practice
// Watch Striver's youtube video for nlogn approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

void solve()
{
  int n;
  cin >> n;
  int a[n];
  forn(i, n)
          cin >>
      a[i];
  vector<int> ans;
  ans.pb(a[0]);
  for (int i = 1; i < n; i++)
  {
    if (ans.back() <= a[i])
      ans.pb(a[i]);
    else
    {
      int l = 0, r = ans.size() - 1;
      int inx = 0;
      while (l <= r)
      {
        int mid = l + (r - l) / 2;
        if (ans[mid] > a[i])
        {
          inx = mid;
          r = mid - 1;
        }
        else
          l = mid + 1;
      }
      ans[inx] = a[i];
    }
  }
  cout << ans.size() << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
