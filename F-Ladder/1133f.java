/* Very good observation by Harsha Swaraj
   He used Bfs to solve this problem
   Greedily picked max degree vertex applied bfs from there

   Spanning tree can also be formed using bfs and dfs
   while minimum spanning tree is formed by only 2 algo.
   Any comments on my guess?
   */

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

public class Solution {

  static ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
  static int degree[];
  static boolean vis[];

  static void bfs(int mde) {
    Queue<Integer> q = new LinkedList<>();
    q.add(mde);
    vis[mde] = true;
    while (!q.isEmpty()) {
      int v = q.remove();
      ArrayList<Integer> list = edges.get(v);
      for (int u : list) {
        if (!vis[u]) {
          vis[u] = true;
          q.add(u);
          System.out.println(v + " " + u);
        }
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int n = Integer.parseInt(s[0]);
    int m = Integer.parseInt(s[1]);
    for (int i = 0; i <= n; i++)
      edges.add(new ArrayList<>());

    degree = new int[n + 1];
    vis = new boolean[n + 1];
    for (int i = 0; i < m; i++) {
      s = bf.readLine().trim().split("\\s+");
      int p = Integer.parseInt(s[0]);
      int q = Integer.parseInt(s[1]);
      edges.get(p).add(q);
      edges.get(q).add(p);
      degree[p]++;
      degree[q]++;
    }
    int max_deg_ele = 1;
    for (int i = 2; i <= n; i++) {
      if (degree[i] > degree[max_deg_ele])
        max_deg_ele = i;
    }
    bfs(max_deg_ele);
  }
}
