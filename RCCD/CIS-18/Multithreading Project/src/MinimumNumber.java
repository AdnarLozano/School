// File Name : MinimumNumber.java

public class MinimumNumber implements Runnable
{
   private int[] nmb;
   public MinimumNumber(int[] nmb)
   {
      this.nmb = nmb;
   }
   public void run()
   {
      int smallest = nmb[0];
	  for(int i=1; i< nmb.length-1; i++)
        {
          if (nmb[i] < smallest)
           smallest = nmb[i];           
        }
		System.out.println("Smallest Number is : " + smallest);
   }
}