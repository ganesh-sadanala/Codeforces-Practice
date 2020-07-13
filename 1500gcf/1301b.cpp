// considering this pbm is slightly different from workout of
// google kickstart WORKOUT pbm
// ternary search works but gives tle
// So Greedy approach works -> Between two poles
// Refer : Editorial
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

int n;
vector<ll> a;
void solve()
{
  cin >> n;
  ll mx = -1, mn = 1e9;
  ll x;
  cin >> x;
  a.pb(x);
  for (int i = 1; i < n; i++)
  {
    cin >> x;
    a.pb(x);
    if (a[i - 1] == -1 && a[i] != -1)
    {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }
    if (a[i - 1] != -1 && a[i] == -1)
    {
      mn = min(mn, a[i - 1]);
      mx = max(mx, a[i - 1]);
    }
  }
  ll k = (mn + mx) / 2;
  mx = -1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == -1)
      a[i] = k;
    if (i)
      mx = max(mx, abs(a[i] - a[i - 1]));
  }
  cout << mx << " " << k << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
    a.clear();
  }
}
