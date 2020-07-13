// Refer: Editorial
// I lost simple observation
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
  string str1, str2;
  cin >> str1 >> str2;
  if (str1.size() != str2.size())
    cout << "NO";
  else if (str1 == str2)
    cout << "YES";
  else
  {
    int n = str1.size();
    bool s1f = false, s2f = false;
    for (int i = 0; i < n; i++)
    {
      if (str1[i] == '1')
        s1f = true;
      if (str2[i] == '1')
        s2f = true;
    }
    if ((!s1f) || (!s2f))
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
