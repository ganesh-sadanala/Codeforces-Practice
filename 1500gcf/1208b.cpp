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

void solve()
{
  int n;
  cin >> n;
  ll a[n];
  forn(i, n)
          cin >>
      a[i];
  unordered_map<ll, ll> ma;
  ll ans = n;
  for (int i = 0; i < n; i++)
  {
    bool isValid = true;
    for (int j = 0; j < i; j++)
    {
      ma[a[j]]++;
      if (ma[a[j]] == 2)
      {
        isValid = false;
        break;
      }
    }

    int k = n;
    for (int j = n - 1; j >= i; j--)
    {
      ma[a[j]]++;
      if (ma[a[j]] == 1)
        k = j;
      else
        break;
    }
    if (isValid)
      ans = min(ans, k - i);

    ma.clear();
  }
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}
