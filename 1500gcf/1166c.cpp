// Refer: Editorial

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
  ll a[n];
  forn(i, n)
          cin >>
      a[i];
  // Key idea is 2*|x| <= 2*|y|
  for (int i = 0; i < n; i++)
    a[i] = abs(a[i]);
  sort(a, a + n);
  ll res = 0;
  for (int i = 0; i < n; i++)
  {
    int l = i + 1, r = n - 1;
    int ans = i;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (a[i] <= 2 * a[mid] && a[mid] <= 2 * a[i])
      {
        l = mid + 1;
        ans = mid;
      }
      else
        r = mid - 1;
    }
    res = res + (ans - i);
  }
  cout << res << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
