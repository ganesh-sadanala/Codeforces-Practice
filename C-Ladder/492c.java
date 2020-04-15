import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Codeforces
{
    static class Mark
    {
        int a,b;
        Mark(int a,int b)
        {
            this.a=a;
            this.b=b;
        }
    }
    static class comparator implements Comparator<Mark>
    {
        public int compare(Mark a,Mark b)
        {
              return a.b-b.b;
        }
    }
    // Use priority queue idea only when data is changing its order
  static ArrayList<Mark> list=new ArrayList<>();
    static void solve(int n,int r,long avg,long cavg,long sum)
    {
       int sz=list.size();
       long ecnt=0;
       for(int i=0;i<sz;i++)
       {
           if(cavg>=avg)
             break;

           Mark m=list.get(i);
           long p=Math.min(avg*n-sum,r-m.a);  // This line to be used in many pbms (reduces number of computations)
           ecnt+=(p*m.b);
           sum+=p;
           cavg=sum/n;
       }
       System.out.println(ecnt);
    }

	public static void main (String[] args) throws java.lang.Exception
	{
	   BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
	   String s[]=bf.readLine().trim().split("\\s+");
	   int n=Integer.parseInt(s[0]);
	   int r=Integer.parseInt(s[1]);
	   long avg=Long.parseLong(s[2]);
	   long cavg=0;
	   for(int i=0;i<n;i++)
	   {
	       s=bf.readLine().trim().split("\\s+");
	       int a=Integer.parseInt(s[0]);
	       int b=Integer.parseInt(s[1]);
	       cavg+=a;
	       if(a<r)
	         list.add(new Mark(a,b));
	   }
	   long sum=cavg;
	   cavg=sum/n;
	   if(cavg>=avg)
	     System.out.println(0);
	   else  {

	     Collections.sort(list,new comparator());
	     solve(n,r,avg,cavg,sum);

	   }
	}
}
