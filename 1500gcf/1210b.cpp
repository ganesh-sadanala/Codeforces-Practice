// Refer Editorial
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
  ll sum = 0;
  int n;
  cin >> n;
  ll a[n];
  forn(i, n)
  {
    cin >> a[i];
    sum += a[i];
  }
  if (sum & 1)
    cout << "NO";
  else
  {
    sort(a, a + n);
    sum -= a[n - 1];
    if (sum < a[n - 1])
      cout << "NO";
    else
      cout << "YES";
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
