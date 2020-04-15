// Greedy these constructive adhoc things are logical
// Don't go madly with test cases

// Where i have failed -> In finding the base case
// take min 0's when failed
// 5 one's and 1 zero => m>2*n+2         110111
// 3 zero's and 1 one => n>m+1           100

// else /...

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces {
  static void solve(int n, int m) {
    if (n > m + 1 || m > 2 * n + 2) {
      System.out.println(-1);
      return;
    } // zeros ekkuva untey 010 follow avvali (nenu edhi follow avvaley)
    if (n >= m) {
      for (int i = 0; i < m; i++)
        System.out.print("01");
      for (int i = 0; i < n - m; i++)
        System.out.print("0");
    } // else if ones ekkuva untey 110 (edhi okkatey follow ayyanu , modhu other cases
      // kuda consider chey)

    else {
      int j = 1;
      for (int i = 0; i < n; i++) {
        // consider T5 for this cond.
        if (j <= (m - n)) {
          System.out.print("1");
          j++;
        }
        System.out.print("10");
      }

      for (int i = 0; i < m - 2 * n; i++)
        System.out.print("1");
    }

    System.out.println();
  }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    // int t=Integer.parseInt(bf.readLine());
    // while(t-->0){
    String s[] = bf.readLine().trim().split("\\s+");
    int zero = Integer.parseInt(s[0]);
    int one = Integer.parseInt(s[1]);
    solve(zero, one);// }
  }
}
