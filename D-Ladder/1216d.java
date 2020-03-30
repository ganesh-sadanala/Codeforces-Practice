//Good Math question
//Where did i fail: Found gcd for the given numbers
//Actual answer: Find gcd for the missing numbers
//What is the max : the max number
//Why: To minimize the number of people
import java.util.*;
import java.io.*;

class Solution
{
static long gcd(long a,long b)
  {
    if(a==0)
      return b;

      return gcd(b%a,a);
  }
  // static long mod = 998244353;
  static void solve(long a[],int n)
  {
    long max=a[0];
    for(int i=1;i<n;i++)
    {
      max=Math.max(max,a[i]);
    }
    long gcd=max-a[0];
    for(int i=1;i<n;i++)
    {
      gcd=gcd(gcd,max-a[i]);
    }
    long sum=0;
    for(int i=0;i<n;i++)
    {
      sum+=(max-a[i]);
    }
    System.out.println(sum/gcd+" "+gcd);
  }
  public static void main(String[] ks) throws Exception {

    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    int n=Integer.parseInt(bf.readLine());
    long a[]=new long[n];
    String s[]=bf.readLine().trim().split("\\s+");
    for(int i=0;i<n;i++)
    {
      a[i]=Long.parseLong(s[i]);
    }
    solve(a,n);
    }
  }
}
