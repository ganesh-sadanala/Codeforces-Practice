// Refer: Editorial
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

ll mod = (ll)1e9 + 7;
ll p(ll x, ll y)
{
  if (y == 0)
    return 1 % mod;

  ll temp = p(x, y / 2);
  ll ans = ((temp % mod) * (temp % mod)) % mod;
  if (y % 2 == 0)
    return ans;

  return ((x % mod) * ans) % mod;
}
void solve()
{
  ll n, m;
  cin >> n >> m;
  ll ext = (p(2, m) + mod - 1) % mod;
  cout << p(ext, n);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}
