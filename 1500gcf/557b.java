// Easy but small variation of binary search to avoid tle and wa

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
  static int n;
  static double w;
  static Double arr[];
  static BufferedReader bf;
  static StringBuffer str = new StringBuffer("");

  static boolean f(double mid) {
    double girl = mid / (n * 3);
    double boy = 2 * mid / (n * 3);

    return arr[0] >= girl && arr[n] >= boy;
  }

  static void solve() throws Exception {

    String s[] = bf.readLine().trim().split("\\s+");
    n = Integer.parseInt(s[0]);
    w = Double.parseDouble(s[1]);

    arr = new Double[2 * n];
    s = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < (2 * n); i++)
      arr[i] = Double.parseDouble(s[i]);

    Arrays.sort(arr);
    double ans = arr[0];
    double l = 0, r = w;

    for (int i = 0; i < 100; i++) {
      double mid = l + (r - l) / 2;
      if (f(mid)) {
        ans = mid;
        l = mid;
      } else
        r = mid;
    }
    str.append(String.format("%.12f", ans));
  }

  public static void main(String[] args) throws java.lang.Exception {
    bf = new BufferedReader(new InputStreamReader(System.in));
    solve();
    System.out.print(str);
  }
}
