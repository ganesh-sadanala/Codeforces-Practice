// Refer: Editorial
// The greedy approach is that 0, 1, 2 mixed sets after that everything is
// a same repetition.
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
  ll r, g, b;
  cin >> r >> g >> b;
  ll mn = min({r, g, b});
  ll res = 0;
  for (ll i = 0; i <= min(mn, 3ll); i++)
  {
    ll ans = 0;
    ans += (r - i) / 3;
    ans += (g - i) / 3;
    ans += (b - i) / 3;
    ans += i;
    res = max(res, ans);
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
