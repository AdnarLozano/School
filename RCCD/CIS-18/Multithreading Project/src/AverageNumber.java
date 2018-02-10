// AverageNumber.java

public class AverageNumber implements Runnable
{
   int n;
   private int[] num;
   double avg;
   public AverageNumber(int[] num)
   {
      this.num = num;
   }
   public void run()
   {
	
      for(int i = 1; i < num.length-1; i++)
	   {
		  n = n+num[i];
		  avg = (double)n/i;
	   }
	   System.out.println("Average Number is : "+avg);
   }
}

