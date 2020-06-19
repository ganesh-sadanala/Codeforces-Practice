// Easy question with tricky test cases
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array
#define init(arr) memset(arr, 0, sizeof(arr))
#define endl "\n"
#define mp make_pair

int n;
void solve()
{
  if (n <= 3)
    cout << "NO\n";
  else if (n % 2 == 0)
  {
    cout << "YES\n";
    cout << "1 * 2 = 2\n";
    cout << "3 * 4 = 12\n";
    cout << "2 * 12 = 24\n";
    if (n == 4)
      return;
    for (int i = 5; i <= n; i += 2)
      cout << (i + 1) << " - " << i << " = "
           << "1\n";

    int rem = (n - 4) / 2;
    if (rem != 1)
    {
      for (int i = 0; i < rem; i += 2)
        cout << 1 << " * " << 1 << " = "
             << "1\n";
    }
    rem = rem / 2;
    while (rem > 1)
    {
      for (int i = 1; i <= rem; i += 2)
        cout << 1 << " * " << 1 << " = "
             << "1\n";
      rem /= 2;
    }
    cout << "24 * 1 = 24\n";
  }
  else
  {
    cout << "YES\n";
    cout << "5 - 2 = 3\n";
    cout << "3 - 1 = 2\n";
    cout << "3 * 2 = 6\n";
    cout << "6 * 4 = 24\n";
    if (n == 5)
      return;
    for (int i = 6; i <= n; i += 2)
      cout << (i + 1) << " - " << i << " = "
           << "1\n";

    int rem = (n - 5) / 2;
    if (rem != 1)
    {
      for (int i = 0; i < rem; i += 2)
        cout << 1 << " * " << 1 << " = "
             << "1\n";
    }
    rem = rem / 2;
    while (rem > 1)
    {
      for (int i = 1; i <= rem; i += 2)
        cout << 1 << " * " << 1 << " = "
             << "1\n";
      rem /= 2;
    }
    cout << "24 * 1 = 24\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  solve();
}
