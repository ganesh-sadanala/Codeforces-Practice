// This is the first C level problem related to games
// Adhoc question
// Take best in the worst case so that you can get optimal

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

public class Solution {

  public static void main(String[] args) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int n = Integer.parseInt(s[0]);
    int x = Integer.parseInt(s[1]);
    int y = Integer.parseInt(s[2]);
    if (x > y)
      System.out.println(n);
    else {
      s = bf.readLine().trim().split("\\s+");
      Integer a[] = new Integer[n];
      for (int i = 0; i < n; i++)
        a[i] = Integer.parseInt(s[i]);
      Arrays.sort(a);
      int ans = 0;
      for (int i = 0; i < n; i += 2) {
        ans += (a[i] <= x) ? 1 : 0;
      }

      System.out.println(ans);
    }
  }
}
