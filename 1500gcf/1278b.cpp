// Refer: Editorial
// I did not get the parity idea a+b=x*(x+1)/2 then both
// a and b should be even or both odd
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

bool ok(ll s, ll d)
{
  ll sum = s * (s + 1) / 2;
  if (sum < d)
    return false;

  return sum % 2 == d % 2;
}
void solve()
{
  ll a, b;
  cin >> a >> b;
  ll d = abs(a - b);
  ll res = 1;
  if (d == 0)
  {
    cout << 0 << endl;
    return;
  }
  while (!ok(res, d))
    res++;

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
