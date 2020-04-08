// I got the idea but i applied in the form of DP -> which increased the
// complexity of code
// I should have applied the same idea in greedy fashion
// Adjacent 01,10 swap else flip both
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces {
  static int s1[] = new int[1000001];
  static int s2[] = new int[1000001];

  static int solve(int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i])
        continue;

      if (i == n - 1) {
        if (s1[i] != s2[i])
          res++;
      } else {
        if (s1[i] != s2[i]) {
          if (s2[i + 1] == s1[i] && s2[i] == s1[i + 1]) {
            s1[i] = s2[i];
            s1[i + 1] = s2[i + 1];
            i++;
            res++;
          } else {
            s1[i] = s2[i];
            res++;
          }
        }
      }

    }
    return res;
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    String s = bf.readLine();
    for (int i = 0; i < n; i++)
      s1[i] = Integer.parseInt(s.charAt(i) + "");
    s = bf.readLine();
    for (int i = 0; i < n; i++)
      s2[i] = Integer.parseInt(s.charAt(i) + "");

    System.out.println(solve(n));
  }
}
