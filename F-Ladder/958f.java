// Efficient approach is using sliding window approach
// Improvement
// Reference -> http://dj3500.webfactional.com/hc2-2018-editorial.pdf
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces {
  static String solve(int []a,int []k)
    {
        int n=a.length;
        int m=k.length;
        int len=0;
        for(int i=1;i<m;i++)
            len+=k[i];

        int l=1,r=len;
        int cnt[m];
        while(r<n)
        {
            Arrays.fill(cnt,0);
            for(int i=l;i<=r;i++)
              cnt[a[i]]++;

            int i=0;
            for(i=1;i<m;i++)
            {
                if(cnt[i]!=b[i])
                  break;
            }
            if(i==m)
              return "YES";

            l++;
            r++;

        }
    }

  public static void main(String[] args) throws java.lang.Exception {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    String s[] = bf.readLine().trim().split("\\s+");
    int n = Integer.parseInt(s[0]);
    int m = Integer.parseInt(s[1]);
    s = bf.readLine().trim().split("\\s+");
    int a[] = new int[n + 1];
    int k[] = new int[m + 1];
    for (int i = 1; i <= n; i++)
      a[i] = Integer.parseInt(s[i - 1]);
    s = bf.readLine().trim().split("\\s+");
    for (int i = 1; i <= m; i++)
      k[i] = Integer.parseInt(s[i - 1]);

    System.out.println(solve(a, k));
  }
}
