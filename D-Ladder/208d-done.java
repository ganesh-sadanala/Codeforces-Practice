/*
 * Mistake: Don't blindly go with binary search every time when u find array is
 * sorted (check the monotonicity). See the size (It is 5). Apply brute force, Time complexity : O(5*n)
 */

/*
 * import java.util.*;
 *
 * import java.io.*;
 *
 * class Solution {
 *
 * // static long mod = 998244353;
 *
 * static long solve(long[] arr, long val, long total, long res[]) { int n =
 * arr.length; int l = 0, r = n - 1; while (total > 0) { l = 0; r = n - 1; if
 * (total < arr[0]) break;
 *
 * long temp = total; while (l <= r) { int mid = l + (r - l) / 2;
 *
 * if (((mid == n - 1) && arr[mid] <= total) || (arr[mid] == total) || (mid < n
 * - 1 && (arr[mid] <= total && arr[mid + 1] > total))) { total -= arr[mid];
 * res[mid]++; break; }
 *
 * else if (arr[mid] < total) l = mid + 1;
 *
 * else r = mid - 1;
 *
 * } if (temp == total) break; } return total; }
 *
 * public static void main(String[] ks) throws Exception {
 *
 * BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
 *
 * String s[] = bf.readLine().trim().split("\\s+"); int n =
 * Integer.parseInt(s[0]); s = bf.readLine().trim().split("\\s+"); long a[] =
 * new long[n]; for (int i = 0; i < n; i++) a[i] = Long.parseLong(s[i]);
 *
 * s = bf.readLine().trim().split("\\s+"); long b[] = new long[5]; for (int i =
 * 0; i < 5; i++) b[i] = Long.parseLong(s[i]);
 *
 * long res[] = new long[5]; Arrays.fill(res, 0); long total = 0; for (int i =
 * 0; i < n; i++) { total += a[i]; total = solve(b, a[i], total, res); } for
 * (int i = 0; i < 5; i++) System.out.print(res[i] + " ");
 *
 * System.out.println("\n" + total); } }
 */

// Refer:https://codeforces.com/blog/entry/4930
import java.util.*;

import java.io.*;

class Solution {

  // static long mod = 998244353;

  static long solve(long[] arr, long val, long total, long res[]) {
    for (int i = 4; i >= 0; i--) {
      long p = total / arr[i];
      res[i] += p;
      total -= p * arr[i];
    }
    return total;
  }

  public static void main(String[] ks) throws Exception {

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    String s[] = bf.readLine().trim().split("\\s+");
    int n = Integer.parseInt(s[0]);
    s = bf.readLine().trim().split("\\s+");
    long a[] = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = Long.parseLong(s[i]);

    s = bf.readLine().trim().split("\\s+");
    long b[] = new long[5];
    for (int i = 0; i < 5; i++)
      b[i] = Long.parseLong(s[i]);

    long res[] = new long[5];
    Arrays.fill(res, 0);
    long total = 0;
    for (int i = 0; i < n; i++) {
      total += a[i];
      total = solve(b, a[i], total, res);
    }
    for (int i = 0; i < 5; i++)
      System.out.print(res[i] + " ");

    System.out.println("\n" + total);
  }
}
