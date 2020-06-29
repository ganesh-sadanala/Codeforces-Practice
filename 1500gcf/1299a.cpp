/*
Key conversion:
A | B has all the bits where A or B have 1, set to 1.

A | B — B has only those bits set to 1 where A has a 1 but B doesn't have a 1. If B had a 1, then A | B would have a 1 in that position and — B would set that bit to 0.

So it is equivalent to A & ~ B
*/
// Refer : Editorial
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
  ll pref[n];
  ll suff[n];
  forn(i, n)
          cin >>
      a[i];
  pref[0] = INT_MAX;
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] & (~a[i - 1]);
  suff[n - 1] = INT_MAX;
  for (int i = n - 2; i >= 0; i--)
    suff[i] = suff[i + 1] & (~a[i + 1]);

  ll mx = 0;
  int ele_inx = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      ll temp = a[i] & suff[i];
      if (temp > mx)
      {
        mx = temp;
        ele_inx = i;
      }
    }
    else if (i == n - 1)
    {
      ll temp = a[i] & pref[i];
      if (temp > mx)
      {
        mx = temp;
        ele_inx = i;
      }
    }
    else
    {
      ll temp = a[i] & pref[i] & suff[i];
      if (temp > mx)
      {
        mx = temp;
        ele_inx = i;
      }
    }
  }
  cout << a[ele_inx] << " ";
  forn(i, n)
  {
    if (i != ele_inx)
      cout << a[i] << " ";
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
