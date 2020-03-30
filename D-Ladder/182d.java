import java.util.*;
import java.io.*;

//Mind block
//Thanks to Ashish Gupta and Harsh Swaraj

public class Solution {
  static int solve(String s1, String s2, int n1, int n2) {
    // Why 1 because to avoid divide by zero error
    int l = Math.min(n1, n2);
    int ans = 0;
    for (int i = 1; i <= l; i++) {
      boolean flag = true;
      // Till i a substring of lower length string if it is a divisor of s1 and s2
      if (n1 % i == 0 && n2 % i == 0) {
        // Actual Check whether the substring is actually a divisor to s1
        for (int j = i; j < n1; j++) {
          // This line is awesome
          // Modulo comparison actually avoids extra burden
          // Assuming s1 is the string
          if (s1.charAt(j % i) != s1.charAt(j)) {
            flag = false;
            break;
          }
        }
        if (flag) {
          for (int j = 0; j < n2; j++) {
            if (s1.charAt(j % i) != s2.charAt(j)) {
              flag = false;
              break;
            }
          }
        }
        if (flag)
          ans++;
      }
    }
    return ans;
  }

  public static void main(String[] ks) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s1 = bf.readLine();
    String s2 = bf.readLine();
    int n1 = s1.length();
    int n2 = s2.length();
    System.out.println(solve(s1, s2, n1, n2));
  }
}
