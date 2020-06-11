// Easy one: failed to handle edge cases
// Leverage the givven test cases as well as some guess test cases
// Generally smaller length tc are used to handle edge cases

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

string s;
void solve()
{
  int sz = s.size();
  int lps[sz];
  int len = 0, i = 0;
  lps[0] = 0;
  i++;
  while (i < sz)
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
        len = lps[len - 1];

      else
      {
        lps[i] = len;
        i++;
      }
    }
  }

  if (lps[sz - 1] != 0)
  {
    int offset = lps[sz - 1];
    // Handling cases like qwertyqwertyqwerty
    for (int i = 0; i < sz - 1; i++)
    {
      if (lps[i] == offset)
      {
        cout << s.substr(0, offset);
        return;
      }
    }

    // Handling whether there is middle substring
    offset = lps[offset - 1];
    if (offset != 0)
      cout << s.substr(0, offset) << endl;
    else
      cout << "Just a legend\n";
  }
  else
    cout << "Just a legend\n";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  solve();
}
