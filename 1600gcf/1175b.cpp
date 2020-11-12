// Getting Iterative idea is difficult
// kind of Obseravation strategy

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl "\n"

const ll INF = 1ll << 32;
const int N = 2e5 + 5;
int cnt = 0;
stack<ll> s;

ll f()
{
  // for add purpose
  // kind of base case
  s.push(1);
  ll res = 0;
  forn(i, cnt)
  {
    string t;
    cin >> t;
    if (t == "for")
    {
      ll x;
      cin >> x;
      ll temp = min(INF, x * s.top());
      s.push(temp);
    }
    else if (t == "end")
    {
      s.pop();
    }
    else
    {
      res += s.top();
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> cnt;
  ll res = f();
  if (res >= INF)
    cout << "OVERFLOW!!!\n";
  else
    cout << res << "\n";
}
/** My recursive sol works if there for for...end end if there is no add after end */
// Help me solve using recursive
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// #define pb push_back
// #define forn(i, n) for (int i = 0; i < n; i++)
// #define ll long long
// #define endl "\n"

// const int N = 2e5 + 5;
// int cnt = 0;
// bool flag = false;

// int f(int x)
// {
//     if(x < 0){
//         flag = true;
//         return x;
//     }

//     if(cnt == 0)
//         return x;

//     string str;
//     getline(cin, str);
//     cnt--;

//     if(str.size()>3)
//     {
//         int m_val = stoi(str.substr(4)) * f(0);
//         return m_val;
//     }

//     else if(str == "add")
//     {
//         x++;
//         x += f(0);
//     }

//     return x;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin>>cnt;
//     int res = 0;
//     while(cnt > 0)
//         res += f(0);
//     if(flag)
//         cout<<"OVERFLOW!!!\n";
//     else
//         cout<<res<<"\n";
// }
