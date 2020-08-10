// Refer: Errichto code
// Yet an another question using lps and KMP strings
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const int N = 1e5 + 1;
int LPS(string &s)
{
  int n = s.size();
  int lps[n];
  int i = 1;
  int len = 0;
  lps[0] = 0;

  while (i < n)
  {
    if (s[i] == s[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps[n - 1];
}
void solve()
{
  string s, t, ans;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int cnts[2];
  cnts[0] = cnts[1] = 0;
  forn(i, n)
      cnts[s[i] - '0']++;

  forn(i, m)
  {
    if (t[i] == '0')
      cnts[0]--;
    else
      cnts[1]--;
  }

  if (cnts[0] < 0 || cnts[1] < 0)
    cout << s << endl;
  else
  {
    ans = t;
    int len = LPS(t);
    while (true)
    {
      int zs = cnts[0], os = cnts[1];
      for (int i = len; i < m; i++)
      {
        if (t[i] == '0')
          cnts[0]--;
        else
          cnts[1]--;
      }
      if (cnts[0] < 0 || cnts[1] < 0)
      {
        for (int i = 0; i < zs; i++)
          ans += "0";

        for (int i = 0; i < os; i++)
          ans += "1";

        break;
      }
      else
      {
        for (int i = len; i < m; i++)
          ans += t[i];
      }
    }
    cout << ans << endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}
