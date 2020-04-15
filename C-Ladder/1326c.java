/* package codechef; // don't place package name! */

// Got the idea for sum but to find the number of ways-> failed
// Need to practice a lot on combinatorics

// Refer editorial for combinatorics explanation

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces {
  static void solve(long n, long k, long[] a) {
    long ways = 1, mod = 998244353, sum = 0;
    ArrayList<Integer> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (a[i] > (n - k)) {
        list.add(i);
        sum += a[i];
      }
    }
    for (int i = 0; i < ((int) k - 1); i++) {
      ways *= ((list.get(i + 1) - list.get(i)) % mod);
      ways %= mod;
    }
    System.out.println(sum + " " + ways);
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    String s[] = bf.readLine().trim().split("\\s+");
    long n = Integer.parseInt(s[0]);
    long k = Integer.parseInt(s[1]);
    long a[] = new long[(int) n];
    s = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < n; i++)
      a[i] = Long.parseLong(s[i]);

    solve(n, k, a);
  }
}
