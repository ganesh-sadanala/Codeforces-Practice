/*package whatever //do not write package name here */

// Easy but tricky
// Dfs with coloring
// edge array gives an idea of actual point -> Take an example to understand it
// Odd cycle -> NO
// no cycle -> yes
// even cycle -> yes
// 1 2 1 2.. alternatively

import java.io.*;
import java.util.*;
import java.lang.*;

class Graph {

  static ArrayList<ArrayList<Integer>> edg = new ArrayList<>();
  static int col[] = new int[200001];
  static boolean flag = false;
  static int edge[] = new int[200001];

  static void dfs(int u) {
    ArrayList<Integer> l = edg.get(u);
    for (int v : l) {
      if (col[v] == 0) {
        col[v] = 3 - col[u];
        dfs(v);
      } else if (col[v] == col[u]) {
        flag = true;
        return;
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int v = Integer.parseInt(s[0]);
    int e = Integer.parseInt(s[1]);
    for (int i = 0; i <= v; i++)
      edg.add(new ArrayList<>());
    for (int i = 1; i <= e; i++) {
      s = bf.readLine().trim().split("\\s+");
      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      edg.get(a).add(b);
      edg.get(b).add(a);
      edge[i] = a;
    }
    for (int i = 1; i <= v; i++) {
      if (col[i] == 0) {
        col[i] = 1;
        dfs(i);
      }
    }
    if (flag)
      System.out.println("NO");
    else {
      System.out.println("YES");
      for (int i = 1; i <= e; i++) {
        System.out.print(col[edge[i]] - 1);
      }
      System.out.println();
    }
  }
}
