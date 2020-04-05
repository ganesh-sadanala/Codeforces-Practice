/* Where i have failed: The idea is in a triangle we get the
   minimum adjacency difference */

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

public class Codechef {
  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(bf.readLine());
    Integer a[] = new Integer[n];
    String s[] = bf.readLine().trim().split("\\s+");
    for (int i = 0; i < n; i++)
      a[i] = Integer.parseInt(s[i]);

    Arrays.sort(a);
    ArrayList<Integer> el = new ArrayList<>();
    ArrayList<Integer> ol = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        el.add(a[i]);
      else
        ol.add(a[i]);
    }
    int e = el.size();
    int o = ol.size();
    for (int i = 0; i < e; i++)
      System.out.print(el.get(i) + " ");
    for (int i = o - 1; i >= 0; i--)
      System.out.print(ol.get(i) + " ");

    System.out.println();
  }
}
