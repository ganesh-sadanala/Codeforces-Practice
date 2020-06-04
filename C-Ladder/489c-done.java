// Awesome approach - Although i solved these kind of problems
// didn't get the idea greedily

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces {
  static void solve(int m, int s) {
    if ((s == 0 && m != 1) || (s > 9 * m))
      System.out.println("-1 -1");
    else {
      int s1 = s - 1;
      String min = "";
      StringBuffer max = new StringBuffer("");
      for (int i = 0; i < m; i++) {
        max.append(Math.min(9, s) + "");
        s -= Math.min(9, s);
      }

      for (int i = 0; i < m - 1; i++) {
        min = Math.min(s1, 9) + min;
        s1 -= Math.min(s1, 9);
      }
      min = (1 + s1) + min;
      System.out.println(min + " " + max);
    }
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int m = Integer.parseInt(s[0]);
    int s1 = Integer.parseInt(s[1]);
    solve(m, s1);// }
  }
}
