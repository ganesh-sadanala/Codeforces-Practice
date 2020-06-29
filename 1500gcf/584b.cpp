// Easy -> Forgot that required = Total ways - not required ways
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

ll m = 1e9 + 7;
ll p(ll x, ll y)
{
  ll res = 1;
  while (y > 0)
  {
    if (y & 1)
      res = ((res % m) * (x % m)) % m;

    y >>= 1;
    x = ((x % m) * (x % m)) % m;
  }
  return res % m;
}

void solve()
{
  ll n;
  cin >> n;
  ll ans = (p(3, 3 * n) % m - p(7, n) % m + m) % m;
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}
