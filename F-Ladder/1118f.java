// easy got the idea but did not get the idea how to implement the idea
// see standings for understanding

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.lang.*;

class Graph {

  static ArrayList<ArrayList<Integer>> edg = new ArrayList<>();
  static boolean vis[] = new boolean[300001];
  static int vcnt[][] = new int[300001][3];
  static int vcol[] = new int[300001];
  static int cnt = 0;
  static int tred = 0, tblue = 0;

  static void dfs(int u) {
    ArrayList<Integer> l = edg.get(u);
    vcnt[u][vcol[u]]++;
    vis[u] = true;
    for (int v : l) {
      if (!vis[v]) {
        dfs(v);
        if ((vcnt[v][2] == tblue && vcnt[v][1] == 0) || (vcnt[v][1] == tred && vcnt[v][2] == 0))
          cnt++;

        for (int i = 0; i < 3; i++) {
          vcnt[u][i] += vcnt[v][i];
        }
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int v = Integer.parseInt(bf.readLine());
    String s[] = bf.readLine().trim().split("\\s+");
    for (int i = 1; i <= v; i++) {
      vcol[i] = Integer.parseInt(s[i - 1]);
      if (vcol[i] == 1)
        tred++;
      else if (vcol[i] == 2)
        tblue++;
    }

    for (int i = 0; i <= v; i++)
      edg.add(new ArrayList<>());

    for (int i = 1; i < v; i++) {
      s = bf.readLine().trim().split("\\s+");
      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      edg.get(a).add(b);
      edg.get(b).add(a);
    }
    dfs(1);
    System.out.println(cnt);
  }
}
