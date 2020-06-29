// Learned that in ternary search, 300 iterations would be enough
// https://codeforces.com/blog/entry/3560
// Refer : Editorial

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codechef {
  static int n, m;
  static Long a[];
  static Long b[];
  static StringBuffer str = new StringBuffer("");
  static BufferedReader bf;

  static long fun(int x) {
    long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < x)
        ans += (x - a[i]);
    }
    for (int i = 0; i < m; i++) {
      if (b[i] > x)
        ans += (b[i] - x);
    }
    return ans;
  }

  static void solve() throws Exception {

    String s[] = bf.readLine().trim().split("\\s+");
    n = Integer.parseInt(s[0]);
    m = Integer.parseInt(s[1]);
    a = new Long[n];
    b = new Long[m];
    s = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < n; i++)
      a[i] = Long.parseLong(s[i]);
    s = bf.readLine().trim().split("\\s+");
    for (int j = 0; j < m; j++)
      b[j] = Long.parseLong(s[j]);
    Arrays.sort(a);
    Arrays.sort(b);

    if (a[0] >= b[m - 1])
      str.append(0 + "\n");
    else {
      int l = 1, r = (int) 1e9;
      long ans = Long.MAX_VALUE;
      for (int i = 0; i < 300; i++) {

        if (l > r)
          break;
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        long lans = fun(mid1);
        long rans = fun(mid2);
        ans = Math.min(ans, Math.min(lans, rans));
        if (lans < rans)
          r = mid2;
        else
          l = mid1;
      }
      str.append(ans + "\n");
    }

  }

  public static void main(String[] args) throws java.lang.Exception {
    bf = new BufferedReader(new InputStreamReader(System.in));

    solve();
    System.out.print(str);
  }
}
